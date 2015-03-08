#include "voronoi/Lloyd.h"
#include "lodepng/lodepng.h"
#include "Triangle.h"

int main()
{

  glm::uvec2 size(500, 500);
  std::vector<unsigned char> mData;
  mData.resize(size.x * size.y);
  std::fill(mData.begin(), mData.end(), 0xFF);

  MapGenerate::Triangle(mData, size,
                        glm::vec2(100, 100), 0x25,
                        glm::vec2(400, 100), 0x82,
                        glm::vec2(100, 400), 0xA9);

  lodepng::encode("img1.png", mData, size.x, size.y, LCT_GREY);

  return 0;
}

