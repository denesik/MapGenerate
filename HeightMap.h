#pragma once
#ifndef HEIGHT_MAP_H__
#define HEIGHT_MAP_H__

#include <glm/glm.hpp>
#include <vector>


namespace HeightMap
{
  /// ��������� ��������� ����� ��� DiamondSquare �� ���������.
  struct DiamondSquareRandomDefault
  {
    float operator()(const glm::uvec2 &)
    {
      return static_cast<float>(rand()) / static_cast<float>(RAND_MAX) - 0.5f;
    }
  };

  namespace DiamondSquareImpl
  {
    template<class RandGenerator>
    class DiamondSquareWorker
    {
    public:
      DiamondSquareWorker(std::vector<float> &data, const glm::uvec2 &size, float roughness,
        RandGenerator randGen = RandGenerator())
        : mData(data), mSize(size.x, size.y), mRoughness(roughness), mRandGenerator(randGen),
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
          for(unsigned int y = stride; y < mSizeP2; y += stride * 2)
          {
            for(unsigned int x = stride; x < mSizeP2; x += stride * 2)
            {
              // �����
              const glm::uvec2 mid(x, y);
              // ���� ��� ����� �� ������ � ���� �������, ��� ��� ��������� � ���� ����� �������
              // �� ������������ ��
              if(!ContainsPoint(mid) || IsAnglePoint(mid))
              {
                continue;
              }
              const glm::uvec2 plb(x - stride, y - stride);
              const glm::uvec2 plt(x - stride, y + stride);
              const glm::uvec2 prt(x + stride, y + stride);
              const glm::uvec2 prb(x + stride, y - stride);
              
              // ��������� ������ ��������� �����.
              CreatePoint(mid, stride, plb, plt, prt, prb);
            }
          }

          unsigned int column = 1;
          for(unsigned int y = 0; y < mSizeP2; y += stride)
          {
            for(unsigned int x = stride * column; x < mSizeP2; x += stride * 2)
            {
              // �����
              const glm::uvec2 mid(x, y);
              // ���� ��� ����� �� ������ � ���� �������, ��� ��� ��������� � ���� ����� �������
              // �� ������������ ��
              if(!ContainsPoint(mid) || IsAnglePoint(mid))
              {
                continue;
              }
              const glm::uvec2 pl(x - stride, y);
              const glm::uvec2 pt(x, y + stride);
              const glm::uvec2 pr(x + stride, y);
              const glm::uvec2 pb(x, y - stride);

              // ��������� ������ ����� �� ��������.
              CreatePoint(mid, stride, pl, pt, pr, pb);
            }
            column = column ? 0 : 1;
          }

          stride /= 2;
        }
      }

    private:
      RandGenerator mRandGenerator; // ��������� ��������� �����.
      std::vector<float> &mData;    // ����� �����.
      const glm::uvec2 mSize;       // ������ ����� �����.
      const unsigned int mSizeP2;   // ������ ������� ������ ���������.
      const float mRoughness;

    private:

      /// ������������� ������ ��� �������� �����.
      void CreatePoint(const glm::uvec2 &mid, unsigned int size, const glm::uvec2 &l, const glm::uvec2 &t, const glm::uvec2 &r, const glm::uvec2 &b)
      {
        assert(ContainsPoint(mid));
        float pl = ContainsPoint(l) ? mData[l.y * mSize.x + l.x] : 0.0f;
        float pt = ContainsPoint(t) ? mData[t.y * mSize.x + t.x] : 0.0f;
        float pr = ContainsPoint(r) ? mData[r.y * mSize.x + r.x] : 0.0f;
        float pb = ContainsPoint(b) ? mData[b.y * mSize.x + b.x] : 0.0f;

        float k = static_cast<float>(size) / static_cast<float>(mSizeP2 - 1);
        float pm = (pl + pt + pr + pb) / 4.0f;
        pm += mRoughness * k * mRandGenerator(mid);
        pm = glm::clamp(pm, -1.0f, 1.0f);

        mData[mid.y * mSize.x + mid.x] = pm;
      }

      // ��������� �� ����� � ������� �������.
      bool ContainsPoint(const glm::uvec2 &point)
      {
        return point.x >= 0 && point.x < mSize.x && point.y >= 0 && point.y < mSize.y;
      }

      /// ��������� �� ����� � ����� �� ���� ������� �������.
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

      /// ����� ��������� ������� ������ � �����.
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

  /// ��������� ���� ������� Diamond Square � �������������� ��������� ���������� ��������� �����.
  template<class RandGenerator>
  void DiamondSquare(std::vector<float> &data, const glm::uvec2 &size, float roughness,
                     float lb, float lt, float rt, float tb,
                     RandGenerator randGen = RandGenerator())
  {
    DiamondSquareImpl::DiamondSquareWorker<RandGenerator>(data, size, roughness, randGen)(lb, lt, rt, tb);
  }

  /// ��������� ���� ������� Diamond Square � �������������� ���������� ��������� ����� �� ���������.
  void DiamondSquare(std::vector<float> &data, const glm::uvec2 &size, float roughness,
                     float lb, float lt, float rt, float tb)
  {
    DiamondSquare(data, size, roughness, lb, lt, rt, tb, DiamondSquareRandomDefault());
  }

}


#endif // HEIGHT_MAP_H__
