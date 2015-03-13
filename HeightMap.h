#pragma once
#ifndef HEIGHT_MAP_H__
#define HEIGHT_MAP_H__

#include <glm/glm.hpp>
#include <vector>


namespace HeightMap
{
  /// Генератор случайных чисел для DiamondSquare по умолчанию.
  struct DiamondSquareRandomDefault
  {
    float operator()(const glm::uvec2 &)
    {
      //return static_cast<float>(rand()) / static_cast<float>(RAND_MAX) - 0.5f;
      return static_cast<float>(rand() % 256 - 127);
    }
  };

  namespace DiamondSquareImpl
  {
    template<class RandGenerator>
    class DiamondSquareWorker
    {
    public:
      DiamondSquareWorker(std::vector<float> &data, const glm::uvec2 &size,
        RandGenerator randGen = RandGenerator())
        : mData(data), mSize(size.x, size.y), mRandGenerator(randGen),
          mSizeP2(size.x > size.y ? Pow2(size.x) + 1 : Pow2(size.y) + 1)
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

        unsigned int mPointCreated = 4;

        unsigned int stride = mSizeP2 / 2;
        float k = 1.0f;
        while(stride >= 1)
        {
          k /= 2.0f;

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
              const glm::uvec2 plb(x - stride, y - stride);
              const glm::uvec2 plt(x - stride, y + stride);
              const glm::uvec2 prt(x + stride, y + stride);
              const glm::uvec2 prb(x + stride, y - stride);
              
              // Вычисляем высоту центровой точки.
              CreatePoint(mid, k, plb, plt, prt, prb);
              ++mPointCreated;
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
              const glm::uvec2 pl(x - stride, y);
              const glm::uvec2 pt(x, y + stride);
              const glm::uvec2 pr(x + stride, y);
              const glm::uvec2 pb(x, y - stride);

              // Вычисляем высоты точек на сторонах.
              CreatePoint(mid, k, pl, pt, pr, pb);
              ++mPointCreated;
            }
            column = column ? 0 : 1;
          }

          stride /= 2;
        }

        printf("Points. All: %i, Created: %i\n", mSize.x * mSize.y, mPointCreated);
      }

    private:
      RandGenerator mRandGenerator;
      std::vector<float> &mData;
      const glm::uvec2 mSize;
      const unsigned int mSizeP2;

    private:

      void CreatePoint(const glm::uvec2 &mid, float k, const glm::uvec2 &l, const glm::uvec2 &t, const glm::uvec2 &r, const glm::uvec2 &b)
      {
        assert(ContainsPoint(mid));
        float pl = ContainsPoint(l) ? mData[l.y * mSize.x + l.x] : 0.0f;
        float pt = ContainsPoint(t) ? mData[t.y * mSize.x + t.x] : 0.0f;
        float pr = ContainsPoint(r) ? mData[r.y * mSize.x + r.x] : 0.0f;
        float pb = ContainsPoint(b) ? mData[b.y * mSize.x + b.x] : 0.0f;

        float pm = (pl + pt + pr + pb) / 4.0f;
        pm += 1.0f * k * mRandGenerator(mid);

        //printf("x: %i, y: %i = %i\n", static_cast<unsigned int>(glm::round(mid.y)), static_cast<unsigned int>(glm::round(mid.x)), 
        //  static_cast<int>(pm));
        mData[mid.y * mSize.x + mid.x] = pm;
      }

      bool ContainsPoint(const glm::uvec2 &point)
      {
        return point.x >= 0 && point.x < mSize.x && point.y >= 0 && point.y < mSize.y;
      }

      bool IsAnglePoint(const glm::uvec2 &point)
      {
        // Если это одна из угловых точек, не надо ее вычислять.
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
    };
  }

  /// Генератор шума методом Diamond Square с использованием заданного генератора случайных чисел.
  template<class RandGenerator>
  void DiamondSquare(std::vector<float> &data, const glm::uvec2 &size,
                     float lb, float lt, float rt, float tb,
                     RandGenerator randGen = RandGenerator())
  {
    DiamondSquareImpl::DiamondSquareWorker<RandGenerator>(data, size, randGen)(lb, lt, rt, tb);
  }

  /// Генератор шума методом Diamond Square с использованием генератора случайных чисел по умолчанию.
  void DiamondSquare(std::vector<float> &data, const glm::uvec2 &size,
                     float lb, float lt, float rt, float tb)
  {
    DiamondSquare(data, size, lb, lt, rt, tb, DiamondSquareRandomDefault());
  }

}


#endif // HEIGHT_MAP_H__
