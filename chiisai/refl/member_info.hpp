#pragma once

#include "sized_info.hpp"
#include <cstddef>
#include <ostream>

namespace chiisai::refl {
  class member_info;
}

class chiisai::refl::member_info : public sized_info {
public:
  std::ptrdiff_t offset{0};

public:
  inline member_info() = delete;

  inline member_info(std::size_t _hash, std::string &&_name, std::string &&_type, std::string &&_raw_type, std::size_t _size, std::ptrdiff_t _offset)
    : sized_info{_hash, std::move(_name), std::move(_type), std::move(_raw_type), _size},
      offset{_offset} {
  }

  inline member_info(member_info const &other)
    : sized_info{other},
      offset{other.offset} {
  }

  inline member_info(member_info &&other)
    : sized_info{std::move(other)},
      offset{std::move(other.offset)} {
  }

  inline member_info &operator=(member_info const &other) {
    sized_info::operator=(other);
    offset              = other.offset;
    return *this;
  }

  inline member_info &operator=(member_info &&other) {
    sized_info::operator=(std::move(other));
    offset              = std::move(other.offset);
    return *this;
  }

  template<typename T>
  inline T access_as(void const * const obj) const noexcept {
    return *reinterpret_cast<T *>(reinterpret_cast<std::uintptr_t>(obj) + offset);
  }

  template<typename T>
  inline T &access_as_ref(void const * const obj) const noexcept {
    return *reinterpret_cast<T *>(reinterpret_cast<std::uintptr_t>(obj) + offset);
  }

  template<typename T>
  inline bool is_type() const noexcept {
    return hash == typeid(T).hash_code();
  }

  inline friend std::ostream &operator<<(std::ostream &os, member_info const &info) {
    os << "\t\t"
       << "member_info{" << std::endl;
    os << "\t\t" << '\t'
       << "hash=" << info.hash << "," << '\n';
    os << "\t\t" << '\t'
       << "name=" << info.name << "," << '\n';
    os << "\t\t" << '\t'
       << "type=" << info.type << "," << '\n';
    os << "\t\t" << '\t'
       << "raw_type=" << info.raw_type << "," << '\n';
    os << "\t\t" << '\t'
       << "size=" << info.size << "," << '\n';
    os << "\t\t" << '\t'
       << "offset=" << info.offset << "," << '\n';
    os << "\t\t"
       << "}";
    return os;
  }
};
