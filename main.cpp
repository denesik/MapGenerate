#include "voronoi/Lloyd.h"
#include "lodepng/lodepng.h"
#include "Triangle.h"
#include "Rasterization.h"
#include "image.h"

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


int main()
{

  glm::uvec2 size(500, 500);

  std::vector<unsigned char> mData;
  mData.resize((size.x + 1) * (size.y + 1), 0xFF);

  std::vector<glm::vec2> points;
  points = Generate(20, size);
  Voronoi diagram(points, size);
  diagram();

  auto const &vertex = diagram.GetVertex();
  std::vector<unsigned char> vertexHeight;
  vertexHeight.resize(vertex.size());
  std::generate(vertexHeight.begin(), vertexHeight.end(), []
  {
    return rand() % 255;
  });

  MapGenerate::Rasterization(mData, size, diagram, vertexHeight);

  Image image;
  image.Resize(size.x + 1, size.y + 1);
  image.FillGray(mData);

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


//  lodepng::encode("img1.png", mData, size.x, size.y, LCT_GREY);

  return 0;
}

