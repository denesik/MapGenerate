#include "Triangle.h"

// Ищем барицентрические координаты.
glm::vec3 Barycentric(const glm::vec2 &a, const glm::vec2 &b, const glm::vec2 &c, const glm::vec2 &p)
{
  glm::vec3 u = glm::cross(glm::vec3(c.x - a.x, b.x - a.x, a.x - p.x),
                           glm::vec3(c.y - a.y, b.y - a.y, a.y - p.y));

  // triangle is degenerate, in this case return smth with negative coordinates
  if (glm::abs(u.z) < 1) return glm::vec3(-1.0f, 1.0f, 1.0f);

  return glm::vec3(1.0f - (u.x + u.y) / u.z, u.y / u.z, u.x / u.z);
}



void MapGenerate::Triangle(std::vector<unsigned char> &surface, const glm::uvec2 &size,
                           const glm::vec2 &a, unsigned char c1,
                           const glm::vec2 &b, unsigned char c2,
                           const glm::vec2 &c, unsigned char c3)
{
  assert(surface.size() == size.x * size.y);
  // Ищем ограничивающий прямоугольник для треугольника.
  glm::uvec2 bboxmin(size.x - 1, size.y - 1);
  glm::uvec2 bboxmax(0, 0);
  glm::uvec2 pts[3] = {glm::round(a), glm::round(b), glm::round(c)};

  for(unsigned int i = 0; i < 3; ++i)
  {
      for(unsigned int j = 0; j < 2; ++j)
      {
          bboxmin[j] = glm::max(0U,      glm::min(bboxmin[j], pts[i][j]));
          bboxmax[j] = glm::min(size[j], glm::max(bboxmax[j], pts[i][j]));
      }
  }

  // Проходим по всем точкам в ограничивающем прямоугольнике и
  // если точка попадает в треугольник, раскрашиваем ее.
  glm::uvec2 p;
  for(p.x = bboxmin.x; p.x <= bboxmax.x; ++p.x)
  {
      for(p.y = bboxmin.y; p.y <= bboxmax.y; ++p.y)
      {
          glm::vec3 bc_screen  = Barycentric(a, b, c, p);
          if(bc_screen.x < 0.0f || bc_screen.y < 0.0f || bc_screen.z < 0.0f)
          {
            continue;
          }
          surface[p.y * size.x + p.x] = (c1 + c2 + c3) / 3;
      }
  }
}

