#pragma once

#include "info.hpp"

namespace chiisai::refl {
  class sized_info;
}

class chiisai::refl::sized_info : public info {
public:
  std::size_t size{0};

public:
  inline sized_info() = delete;

  inline sized_info(std::size_t _hash, std::string &&_name, std::string &&_type, std::string &&_raw_type, std::size_t _size)
    : info{_hash, std::move(_name), std::move(_type), std::move(_raw_type)},
      size{_size} {
  }

  inline sized_info(sized_info const &other)
    : info{other} {
    size = other.size;
  }

  inline sized_info(sized_info &&other)
    : info{std::move(other)} {
    size = std::move(other.size);
  }

  inline sized_info &operator=(sized_info const &other) {
    info::operator=(other);
    size          = other.size;
    return *this;
  }

  inline sized_info &operator=(sized_info &&other) {
    info::operator=(std::move(other));
    size          = std::move(other.size);
    return *this;
  }
};
