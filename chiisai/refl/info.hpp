#pragma once

#include <string>

namespace chiisai::refl {
  class info;
}

class chiisai::refl::info {
public:
  std::size_t hash{0};
  std::string name{};
  std::string type{};
  std::string raw_type{};

public:
  inline info() = delete;

  inline info(std::size_t _hash, std::string &&_name, std::string &&_type, std::string &&_raw_type)
    : hash{_hash},
      name{std::move(_name)},
      type{std::move(_type)},
      raw_type{std::move(_raw_type)} {
  }

  inline info(info const &other) {
    hash     = other.hash;
    name     = other.name;
    type     = other.type;
    raw_type = other.raw_type;
  }

  inline info(info &&other) {
    hash     = std::move(other.hash);
    name     = std::move(other.name);
    type     = std::move(other.type);
    raw_type = std::move(other.raw_type);
  }

  inline info &operator=(info const &other) {
    hash     = other.hash;
    name     = other.name;
    type     = other.type;
    raw_type = other.raw_type;
    return *this;
  }

  inline info &operator=(info &&other) {
    hash     = std::move(other.hash);
    name     = std::move(other.name);
    type     = std::move(other.type);
    raw_type = std::move(other.raw_type);
    return *this;
  }
};
