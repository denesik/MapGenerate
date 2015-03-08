#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <glm/glm.hpp>
#include <vector>

namespace MapGenerate
{
  /// Нарисовать треугольник.
  void DrawTriangle(std::vector<unsigned char> &surface, const glm::uvec2 &size,
                   const glm::vec2 &a, unsigned char c1,
                   const glm::vec2 &b, unsigned char c2,
                   const glm::vec2 &c, unsigned char c3);
}

#endif // TRIANGLE_H
