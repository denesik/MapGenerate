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
    float operator()(const glm::vec2 &)
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
        : mData(data), mSize(size.x, size.y), mRandGenerator(randGen)
      {
      }

      void operator()(float lb, float lt, float rt, float rb)
      {
        const glm::vec2 poslb(0.0f, 0.0f);
        const glm::vec2 posrt(mSize.x - 1, mSize.y - 1);

        mData[static_cast<unsigned int>(glm::round(poslb.y)) * mSize.y + static_cast<unsigned int>(glm::round(poslb.x))] = lb;
        mData[static_cast<unsigned int>(glm::round(posrt.y)) * mSize.y + static_cast<unsigned int>(glm::round(poslb.x))] = lt;
        mData[static_cast<unsigned int>(glm::round(posrt.y)) * mSize.y + static_cast<unsigned int>(glm::round(posrt.x))] = rt;
        mData[static_cast<unsigned int>(glm::round(poslb.y)) * mSize.y + static_cast<unsigned int>(glm::round(posrt.x))] = rb;

        float strideX = static_cast<float>(mSize.x - 1);
        float strideY = static_cast<float>(mSize.y - 1);
        float k = 1.0f;
        while(strideX >= 1.0f || strideY >= 1.0f)
        {
          k /= 2.0f;

          float dstrideX = strideX / 2.0f;
          float dstrideY = strideY / 2.0f;

          for(float y = dstrideY; y < mSize.y - 1; y += strideY)
          {
            for(float x = dstrideX; x < mSize.x - 1; x += strideX)
            {
              // центр
              const glm::vec2 mid(x, y);
              const glm::vec2 plb(x - dstrideX, y - dstrideY);
              const glm::vec2 plt(x - dstrideX, y + dstrideY);
              const glm::vec2 prt(x + dstrideX, y + dstrideY);
              const glm::vec2 prb(x + dstrideX, y - dstrideY);
              
              // Вычисляем высоту центровой точки.
              CreatePoint(mid, k, plb, plt, prt, prb);
            }
          }

          for(float y = dstrideY; y < mSize.y - 1; y += strideY)
          {
            for(float x = dstrideX; x < mSize.x - 1; x += strideX)
            {
              // центр
              const glm::vec2 mid(x, y);
              const glm::vec2 plb(x - dstrideX, y - dstrideY);
              const glm::vec2 plt(x - dstrideX, y + dstrideY);
              const glm::vec2 prt(x + dstrideX, y + dstrideY);
              const glm::vec2 prb(x + dstrideX, y - dstrideY);

              // Вычисляем высоты точек на сторонах.
              CreatePoint(glm::vec2(plb.x, mid.y), k, glm::vec2(plb.x - dstrideX, mid.y), plt, mid, plb);
              CreatePoint(glm::vec2(mid.x, prt.y), k, plt, glm::vec2(mid.x, prt.y + dstrideY), prt, mid);
              CreatePoint(glm::vec2(prt.x, mid.y), k, mid, prt, glm::vec2(prt.x + dstrideX, mid.y), prb);
              CreatePoint(glm::vec2(mid.x, plb.y), k, plb, mid, prb, glm::vec2(mid.x, plb.y - dstrideY));
            }
          }
          strideX /= 2.0f;
          strideY /= 2.0f;
        }

      }

    private:
      RandGenerator mRandGenerator;
      std::vector<float> &mData;
      const glm::uvec2 mSize;
    
    private:

      void CreatePoint(const glm::vec2 &mid, float k, const glm::vec2 &l, const glm::vec2 &t, const glm::vec2 &r, const glm::vec2 &b)
      {
        assert(ContainsPoint(mid));
        float pl = ContainsPoint(l) ? mData[static_cast<unsigned int>(glm::round(l.y)) * mSize.x + static_cast<unsigned int>(glm::round(l.x))] : 0.0f;
        float pt = ContainsPoint(t) ? mData[static_cast<unsigned int>(glm::round(t.y)) * mSize.x + static_cast<unsigned int>(glm::round(t.x))] : 0.0f;
        float pr = ContainsPoint(r) ? mData[static_cast<unsigned int>(glm::round(r.y)) * mSize.x + static_cast<unsigned int>(glm::round(r.x))] : 0.0f;
        float pb = ContainsPoint(b) ? mData[static_cast<unsigned int>(glm::round(b.y)) * mSize.x + static_cast<unsigned int>(glm::round(b.x))] : 0.0f;

        float pm = (pb + pt + pr + pb) / 4.0f;
        pm += 1.0f * k * mRandGenerator(mid);

        mData[static_cast<unsigned int>(glm::round(mid.y)) * mSize.x + static_cast<unsigned int>(glm::round(mid.x))] = pm;
      }

      bool ContainsPoint(const glm::vec2 &point)
      {
        return point.x >= 0 && point.x <= mSize.x - 1 && point.y >= 0 && point.y <= mSize.y - 1;
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
