#include "voronoi/Lloyd.h"
#include "lodepng/lodepng.h"
#include "Triangle.h"
#include "Rasterization.h"
#include "image.h"
#include "DiamondSquare.h"
#include "gif-h/gif.h"

#include <stdlib.h>
#include <ctime>
#include <algorithm>
#include <iterator>

std::vector<glm::vec2> Generate(const unsigned int count, const glm::uvec2 &size)
{
  std::vector<glm::vec2> points;
  points.reserve(count);

  unsigned int seed = static_cast<unsigned int>(time(NULL));
  srand(seed);

  struct Generator
  {
    const glm::uvec2 size;
    Generator(const glm::uvec2 &s)
      : size(s)
    {}
    glm::vec2 operator()() {return glm::vec2(rand() % size.x, rand() % size.y);}
  } generator(size);

  std::generate_n(std::back_inserter(points), count, generator);


  std::sort(points.begin(), points.end(),
    [](const glm::vec2 &p1, const glm::vec2 &p2) -> bool
  {
    if(p1.y == p2.y)
      return p1.x > p2.x;
    return p1.y > p2.y;
  });

  auto it = std::unique(points.begin(), points.end(),
    [](const glm::vec2 &p1, const glm::vec2 &p2)
    {
      return p1.x == p2.x && p1.y == p2.y;
    });

  points.resize(std::distance(points.begin(), it));

  return std::move(points);
}

void Print(const std::vector<float> &data, const glm::uvec2 &size)
{
  for(unsigned int y = 0; y < size.y; ++y)
  {
    for(unsigned int x = 0; x < size.x; ++x)
    {
      printf("%f ", data[y * size.x + x]);
    }
    printf("\n");
  }
}

struct WeightedAverage
{
  WeightedAverage(const std::vector<unsigned char> &weight, const glm::uvec2 &size)
    : mWeight(weight), mSize(size)
  {
  }

  glm::vec2 operator()(const glm::vec2 &, const std::vector<unsigned int> &poligon, const std::vector<glm::vec2> &vertex)
  {
    glm::vec2 point;
    unsigned int weight = 0;
    for(auto jt = poligon.begin(); jt != poligon.end(); ++jt)
    {
      glm::uvec2 wp(vertex[*jt]);
      unsigned char w = mWeight[wp.y * mSize.x + wp.x];
      weight += w;

      point += vertex[*jt] * static_cast<float>(w);
    }
    point = point / static_cast<float>(weight);
    return point;
  }

  const std::vector<unsigned char> &mWeight;
  const glm::uvec2 &mSize;
};

int main()
{
  srand(4);

  glm::uvec2 size(300, 300);
  std::vector<float> mData;
  mData.resize((size.x) * (size.y), 0.0f);
  /*
  for(unsigned int y = 150; y < 250; ++y)
  {
    for(unsigned int x = 150; x < 250; ++x)
    {
      mData[y * size.x + x] = 0.1f;
    }
  }
  */

  /*
  GifWriter gw;
  GifBegin(&gw, "height.gif", size.x, 256, 50);

  //for(float i = 0; i < 10; i += 0.1f)
  //for(unsigned int y = 0; y < size.y; ++y)
  {
    DiamondSquare::DiamondSquare(mData, size, 2, 0.0f, 0.0f, 0.0f, 0.0f);
    {
      Image image;
      image.Resize(size.x, 256);
      image.Fill(0xFFFFFFFF);

      unsigned int y = 0;
      for(unsigned int x = 0; x < size.x; ++x)
      {
        unsigned int height = static_cast<unsigned char>((mData[y * size.x + x] + 1.0f) * 127.5f);
        image.DrawPoint(glm::uvec2(x, height), 0x000000FF);
      }

      //image.Save("img.png");
      GifWriteFrame(&gw, &image.Raw()[0], size.x, 256, 10);
    }
  }
  GifEnd(&gw);
*/

  DiamondSquare::DiamondSquare(mData, size, 7, 0.0f, 0.0f, 0.0f, 0.0f);


  std::vector<unsigned char> weight;
  weight.resize(mData.size(), 0);

  for(unsigned int i = 0; i < mData.size(); ++i)
  {
    weight[i] = static_cast<unsigned char>((mData[i] + 1.0f) * 127.5f);
  }

  {
    Image img1;
    img1.Resize(size.x, size.y);
    img1.Fill(0xFFFFFFFF);

    for(unsigned int y = 0; y < size.y; ++y)
    {
      for(unsigned int x = 0; x < size.x; ++x)
      {
        unsigned int color = weight[y * size.x + x];

        unsigned int c = 0x000000FF;
        c |= color << 8;
        c |= color << 16;
        c |= color << 24;
        if(color <= 135) c |= 0x0000FFFF;
        if(color > 135 && color <= 140) c |= 0xFFFF00FF;
        if(color > 140 && color <= 220) c |= 0x00FF00FF;
        img1.DrawPoint(glm::uvec2(x, y), c);
      }
    }
    img1.Save("img1.png");
  }



  std::vector<glm::vec2> points;
  points = Generate((size.x + size.y) * 5, glm::uvec2(size.x - 1, size.y - 1));

  GifWriter gw;
  GifBegin(&gw, "voronoi.gif", size.x, size.y, 50);
  for(unsigned int i = 0; i < 5000; ++i)
  {
    points = Lloyd(points, glm::uvec2(size.x - 1, size.y - 1), WeightedAverage(weight, size));

    // Рисуем анимацию.
    Voronoi diagram(points, glm::uvec2(size.x - 1, size.y - 1));
    diagram();
    const std::vector<glm::vec2> &vertex = diagram.GetVertex();
    const std::vector<Voronoi::Edge> &edge = diagram.GetEdges();

    Image image;
    image.Resize(size.x, size.y);
    image.Fill(0xFFFFFFFF);


    for(auto it = edge.begin(); it != edge.end(); ++it)
    {
      const glm::vec2 &p1 = vertex[(*it).vertex1];
      const glm::vec2 &p2 = vertex[(*it).vertex2];
      image.DrawLine(p1, p2, 0x00FF00FF);
    }
    /*
    for(auto it = edge.begin(); it != edge.end(); ++it)
    {
      const glm::vec2 &p1 = points[(*it).site1];
      const glm::vec2 &p2 = points[(*it).site2];
      image.DrawLine(p1, p2, 0xFF0000FF);
    }
    */
    GifWriteFrame(&gw, &image.Raw()[0], size.x, size.y, 2);
  }
  GifEnd(&gw);

  Voronoi diagram(points, glm::uvec2(size.x - 1, size.y - 1));
  diagram();

  auto const &vertex = diagram.GetVertex();

  Image image;
  image.Resize(size.x, size.y);
  image.Fill(0xFFFFFFFF);

  const std::vector<Voronoi::Edge> &edge = diagram.GetEdges();
  for(auto it = edge.begin(); it != edge.end(); ++it)
  {
    const glm::vec2 &p1 = vertex[(*it).vertex1];
    const glm::vec2 &p2 = vertex[(*it).vertex2];
    image.DrawLine(p1, p2, 0x00FF00FF);
  }

  for(auto it = edge.begin(); it != edge.end(); ++it)
  {
    const glm::vec2 &p1 = points[(*it).site1];
    const glm::vec2 &p2 = points[(*it).site2];
    image.DrawPoint(p1, 0xFF0000FF);
    image.DrawPoint(p2, 0xFF0000FF);
    //image.DrawLine(p1, p2, 0xFF0000FF);
  }

  image.Save("img.png");


  return 0;
}

