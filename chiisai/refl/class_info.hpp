#pragma once

#include "sized_info.hpp"
#include "member_info.hpp"

#include <vector>
#include <ostream>

namespace chiisai::refl {
  class class_info;
}

class chiisai::refl::class_info : public sized_info {
public:
  std::vector<member_info> members{};

public:
  inline class_info() = delete;

  inline class_info(std::size_t _hash, std::string &&_name, std::string &&_type, std::string &&_raw_type, std::size_t _size, std::vector<member_info> &&_members)
    : sized_info{_hash, std::move(_name), std::move(_type), std::move(_raw_type), _size},
      members{std::move(_members)} {
  }

  inline class_info(class_info const &other)
    : sized_info{other} {
    members = other.members;
  }

  inline class_info(class_info &&other)
    : sized_info{std::move(other)} {
    members = std::move(other.members);
  }

  inline class_info &operator=(class_info const &other) {
    sized_info::operator=(other);
    members             = other.members;
    return *this;
  }

  inline class_info &operator=(class_info &&other) {
    sized_info::operator=(std::move(other));
    members             = std::move(other.members);
    return *this;
  }

  inline friend std::ostream &operator<<(std::ostream &os, class_info const &info) {
    os << "class_info{" << '\n';
    os << "\t"
       << "hash=" << info.hash << ',' << '\n';
    os << "\t"
       << "name=" << info.name << ',' << '\n';
    os << "\t"
       << "type=" << info.type << ',' << '\n';
    os << "\t"
       << "raw_type=" << info.raw_type << ',' << '\n';
    os << "\t"
       << "size=" << info.size << ',' << '\n';
    os << "\t"
       << "members=[" << '\n';
    for (auto const &member : info.members) {
      os << member << ", " << std::endl;
    }
    os << "\t"
       << "]," << '\n';
    os << '}';
    return os;
  }
};
