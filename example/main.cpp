#include <iostream>

#include "chiisai/refl/refl.hpp"
#include "player.hpp"

int main() {
  player ply{};
  std::cout << ply.refl << std::endl;
  return 0;
}
