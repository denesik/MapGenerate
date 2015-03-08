#ifndef RASTERIZATION_H
#define RASTERIZATION_H

#include <glm/glm.hpp>
#include <vector>
#include "voronoi/Voronoi.h"

namespace MapGenerate
{

  // Построить карту высот из диаграммы вороного.
  void Rasterization(std::vector<unsigned char> &surface, const glm::uvec2 &size,
                     const Voronoi &diagram, const std::vector<unsigned char> &vertexHeight);

}


#endif // RASTERIZATION_H
