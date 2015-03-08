#include "Rasterization.h"

#include <set>
#include <algorithm>
#include "Triangle.h"

float RotationPoint(const glm::vec2 &a, const glm::vec2 &b, const glm::vec2 &c)
{
  return (b.x - a.x) * (c.y - b.y) - (b.y - a.y) * (c.x - b.x);
}

void SortPointCcw(const std::vector<glm::vec2> &vertex, std::vector<unsigned int> &vertexIndex)
{
  if(vertexIndex.empty())
  {
    return;
  }

  // Ищем самую левую точку.
  // Если таких точек несколько - выбираем верхную

  unsigned int leftVertex = vertexIndex[0];
  for(unsigned int i = 1; i < vertexIndex.size(); ++i)
  {
    if(vertex[leftVertex].x > vertex[vertexIndex[i]].x)
    {
      leftVertex = vertexIndex[i];
    }
    else if(vertex[leftVertex].x == vertex[vertexIndex[i]].x)
    {
      if(vertex[leftVertex].y <= vertex[vertexIndex[i]].y)
      {
        leftVertex = vertexIndex[i];
      }
    }
  }

  // Сортируем точки
  std::set<unsigned int, std::function<bool(unsigned int, unsigned int)> >
  sortedPoints([leftVertex, &vertex](unsigned int a,unsigned int b)
  {
    return RotationPoint(vertex[leftVertex], vertex[a], vertex[b]) > 0;
  });

  for(unsigned int i = 0; i < vertexIndex.size(); ++i)
  {
    if(vertexIndex[i] != leftVertex)
    {
      sortedPoints.insert(vertexIndex[i]);
    }
  }

  vertexIndex.assign(sortedPoints.begin(), sortedPoints.end());
  vertexIndex.push_back(leftVertex);
}


void MapGenerate::Rasterization(std::vector<unsigned char> &surface, const glm::uvec2 &size,
                                const Voronoi &diagram, const std::vector<unsigned char> &vertexHeight)
{
  const glm::uvec2 surfaceSize(size.x + 1, size.y + 1);
  auto const &sites = diagram.GetSites();
  auto const &vertex = diagram.GetVertex();
  auto const &edges = diagram.GetEdges();

  // Подготавливаем массив для заполнения полигонов.
  std::vector<std::vector<unsigned int> > listPoligons;
  listPoligons.reserve(sites.size());
  for(unsigned int i = 0; i < sites.size(); ++i)
  {
    // Резервируем память под 9 вершин (среднее значение с запасом)
    listPoligons.push_back(std::vector<unsigned int>());
    listPoligons.back().reserve(9);
  }

  // Проходим по всем граням и добавляем вершины соответствующим точкам.
  // Каждая вершина продублируется 2 раза, дубликаты не добавляем.
  for(auto it = edges.begin(); it != edges.end(); ++it)
  {
    const Voronoi::Edge &edge = (*it);

    if(std::find(listPoligons[edge.site1].begin(), listPoligons[edge.site1].end(), edge.vertex1) ==
                 listPoligons[edge.site1].end())
    {
      listPoligons[edge.site1].push_back(edge.vertex1);
    }
    if(std::find(listPoligons[edge.site1].begin(), listPoligons[edge.site1].end(), edge.vertex2) ==
                 listPoligons[edge.site1].end())
    {
      listPoligons[edge.site1].push_back(edge.vertex2);
    }
    if(std::find(listPoligons[edge.site2].begin(), listPoligons[edge.site2].end(), edge.vertex1) ==
                 listPoligons[edge.site2].end())
    {
      listPoligons[edge.site2].push_back(edge.vertex1);
    }
    if(std::find(listPoligons[edge.site2].begin(), listPoligons[edge.site2].end(), edge.vertex2) ==
                 listPoligons[edge.site2].end())
    {
      listPoligons[edge.site2].push_back(edge.vertex2);
    }
  }

  // Сортируем вершины полигонов против часовой.
  for(auto it = listPoligons.begin(); it != listPoligons.end(); ++it)
  {
    SortPointCcw(vertex, (*it));
  }

  // Проходим по всем полигонам и рисуем их.
  for(unsigned int i = 0; i < listPoligons.size(); ++i)
  {
    const std::vector<unsigned int> &vertexIndex = listPoligons[i];
    if(vertexIndex.size() < 2)
    {
      continue;
    }
    unsigned int ccolor = 0;
    for(unsigned int j = 0; j < vertexIndex.size(); ++j)
    {
      ccolor += vertexHeight[j];
    }
    ccolor /= vertexIndex.size();

    for(unsigned int j = 1; j < vertexIndex.size(); ++j)
    {
      MapGenerate::DrawTriangle(surface, surfaceSize,
                                sites[i],                   static_cast<unsigned char>(ccolor),
                                vertex[vertexIndex[j]],     vertexHeight[vertexIndex[j]],
                                vertex[vertexIndex[j - 1]], vertexHeight[vertexIndex[j - 1]]);
    }
    MapGenerate::DrawTriangle(surface, surfaceSize,
                              sites[i],                                    static_cast<unsigned char>(ccolor),
                              vertex[vertexIndex[vertexIndex.size() - 1]], vertexHeight[vertexIndex[vertexIndex.size() - 1]],
                              vertex[vertexIndex[0]],                      vertexHeight[vertexIndex[0]]);
  }

}



















