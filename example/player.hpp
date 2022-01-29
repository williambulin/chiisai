#pragma once

#include <string>

#include "chiisai/refl/refl.hpp"

class player {
public:
  enum class type : std::uint8_t {
    pyro,
    heavy,
    medic,
    sniper,
    scout,
    spy,
  };

public:
  std::string name{"unnamed"};
  double      health{100.0};
  type        type_id{type::spy};

public:
  refl_db;
};

refl_class(
  player,
  {
    refl_member(player, name),
    refl_member(player, health),
    refl_member(player, type_id),
  });
