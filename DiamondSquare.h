#pragma once
#ifndef DIAMOND_SQUARE_H__
#define DIAMOND_SQUARE_H__

#include <glm/glm.hpp>
#include <vector>


namespace DiamondSquare
{
  /// Генератор высот в точках для DiamondSquare
  struct PointGenerator
  {
    /// @param data Карта высот.
    /// @param size Размер карты высот.
    /// @param roughness Коэффициент шероховатости.
    PointGenerator(std::vector<float> &data, const glm::uvec2 &size, float roughness)
      : mData(data), mSize(size), mRoughness(roughness)
    {
      srand(3);
    }
    /// @param mid Точка, для которой нужно генерировать высоту.
    /// @param k Коэффициент высоты для данной точки.
    /// @param l Левая точка.
    /// @param t Верхняя точка.
    /// @param r Правая точка.
    /// @param b Нижняя точка.
    float operator()(const glm::uvec2 &, float k,
                     const glm::ivec2 &l, const glm::ivec2 &t, const glm::ivec2 &r, const glm::ivec2 &b)
    {
      float pl = ContainsPoint(l) ? mData[l.y * mSize.x + l.x] : 0.0f;
      float pt = ContainsPoint(t) ? mData[t.y * mSize.x + t.x] : 0.0f;
      float pr = ContainsPoint(r) ? mData[r.y * mSize.x + r.x] : 0.0f;
      float pb = ContainsPoint(b) ? mData[b.y * mSize.x + b.x] : 0.0f;

      float pm = (pl + pt + pr + pb) / 4.0f;
      pm += mRoughness * k * Rand();

      return pm;
    }

    // Находится ли точка в рабочей области.
    bool ContainsPoint(const glm::ivec2 &point)
    {
      return point.x >= 0 && point.x < static_cast<int>(mSize.x) &&
             point.y >= 0 && point.y < static_cast<int>(mSize.y);
    }

    float Rand()
    {
      return static_cast<float>(rand() % 256) / 255.0f - 0.5f;
    }

    const std::vector<float> &mData;
    const glm::uvec2 &mSize;
    const float mRoughness;
  }; 

  namespace DiamondSquareImpl
  {
    template<class RandGenerator>
    class DiamondSquareWorker
    {
    public:
      DiamondSquareWorker(std::vector<float> &data, const glm::uvec2 &size, PointGenerator generator = PointGenerator())
        : mData(data), mSize(size.x, size.y), mPointGenerator(generator),
        mSizeP2(size.x > size.y ? Pow2(size.x - 1) + 1 : Pow2(size.y - 1) + 1)
      {
      }

      void operator()(float lb, float lt, float rt, float rb)
      {
        const glm::uvec2 poslb(0, 0);
        const glm::uvec2 posrt(mSize.x - 1, mSize.y - 1);

        mData[poslb.y * mSize.x + poslb.x] = lb;
        mData[posrt.y * mSize.x + poslb.x] = lt;
        mData[posrt.y * mSize.x + posrt.x] = rt;
        mData[poslb.y * mSize.x + posrt.x] = rb;

        unsigned int stride = mSizeP2 / 2;
        while(stride >= 1)
        {
          float k = static_cast<float>(stride) / static_cast<float>(mSizeP2 - 1);

          for(unsigned int y = stride; y < mSizeP2; y += stride * 2)
          {
            for(unsigned int x = stride; x < mSizeP2; x += stride * 2)
            {
              // центр
              const glm::uvec2 mid(x, y);
              // Если эта точка не входит в нашу область, или она находится в углу нашей области
              // не обрабатываем ее
              if(!ContainsPoint(mid) || IsAnglePoint(mid))
              {
                continue;
              }
              const glm::ivec2 plb(x - stride, y - stride);
              const glm::ivec2 plt(x - stride, y + stride);
              const glm::ivec2 prt(x + stride, y + stride);
              const glm::ivec2 prb(x + stride, y - stride);

              // Вычисляем высоту центровой точки.
              //mData[mid.y * mSize.x + mid.x] = Modf(mPointGenerator(mid, k, plb, plt, prt, prb));
              mData[mid.y * mSize.x + mid.x] = glm::clamp((mPointGenerator(mid, k, plb, plt, prt, prb)), -1.0f, 1.0f);
            }
          }

          unsigned int column = 1;
          for(unsigned int y = 0; y < mSizeP2; y += stride)
          {
            for(unsigned int x = stride * column; x < mSizeP2; x += stride * 2)
            {
              // центр
              const glm::uvec2 mid(x, y);
              // Если эта точка не входит в нашу область, или она находится в углу нашей области
              // не обрабатываем ее
              if(!ContainsPoint(mid) || IsAnglePoint(mid))
              {
                continue;
              }
              const glm::ivec2 pl(x - stride, y);
              const glm::ivec2 pt(x, y + stride);
              const glm::ivec2 pr(x + stride, y);
              const glm::ivec2 pb(x, y - stride);

              // Вычисляем высоты точек на сторонах.
              //mData[mid.y * mSize.x + mid.x] = Modf(mPointGenerator(mid, k, pl, pt, pr, pb));
              mData[mid.y * mSize.x + mid.x] = glm::clamp(mPointGenerator(mid, k, pl, pt, pr, pb), -1.0f, 1.0f);
            }
            column = column ? 0 : 1;
          }

          stride /= 2;
        }
      }

    private:
      std::vector<float> &mData;      // Карта высот.
      const glm::uvec2 mSize;         // Размер карты высот.
      PointGenerator mPointGenerator; // Генератор высот для точек.
      const unsigned int mSizeP2;     // Размер области работы алгоритма.

    private:

      /// Находится ли точка в рабочей области.
      bool ContainsPoint(const glm::uvec2 &point)
      {
        return point.x >= 0 && point.x < mSize.x && point.y >= 0 && point.y < mSize.y;
      }

      /// Находится ли точка в одном из углу рабочей области.
      bool IsAnglePoint(const glm::uvec2 &point)
      {
        if(point.x == 0 && point.y == 0)
          return true;
        if(point.x == 0 && point.y == mSize.y - 1)
          return true;
        if(point.x == mSize.x - 1 && point.y == 0)
          return true;
        if(point.x == mSize.x - 1 && point.y == mSize.y - 1)
          return true;
        return false;
      }

      /// Найти ближайшую степень двойки к числу.
      unsigned int Pow2(unsigned int a)
      {
        a = a - 1;
        a = a | (a >> 1);
        a = a | (a >> 2);
        a = a | (a >> 4);
        a = a | (a >> 8);
        a = a | (a >> 16);

        return a = a + 1;
      }

      float Modf(float val)
      {
        while(val > 1.0f)
        {
          val -= 1.0f;
        }
        while(val < -1.0f)
        {
          val += 1.0f;
        }

        return val;
      }
    };
  }

  /// Генератор шума методом Diamond Square с использованием заданного генератора точек.
  template<class PointGenerator>
  void DiamondSquare(std::vector<float> &data, const glm::uvec2 &size,
                     float lb, float lt, float rt, float tb,
                     PointGenerator generator = PointGenerator())
  {
    DiamondSquareImpl::DiamondSquareWorker<PointGenerator>(data, size, generator)(lb, lt, rt, tb);
  }

  /// Генератор шума методом Diamond Square с использованием генератора точек по умолчанию.
  void DiamondSquare(std::vector<float> &data, const glm::uvec2 &size, float roughness,
                     float lb, float lt, float rt, float tb)
  {
    DiamondSquare(data, size, lb, lt, rt, tb, PointGenerator(data, size, roughness));
  }
}


#endif // DIAMOND_SQUARE_H__
