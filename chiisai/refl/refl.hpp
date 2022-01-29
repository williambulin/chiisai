#pragma once

#include "info.hpp"
#include "sized_info.hpp"
#include "member_info.hpp"
#include "class_info.hpp"

#define refl_member(class_name, member_name) \
  { \
    typeid(class_name::member_name).hash_code(), \
      #member_name, \
      typeid(class_name::member_name).name(), \
      typeid(class_name::member_name).raw_name(), \
      sizeof(class_name::member_name), \
      offsetof(class_name, member_name), \
  }

#define refl_db static const chiisai::refl::class_info refl

#define refl_class(class_name, ...) \
  inline const chiisai::refl::class_info class_name::refl { \
    typeid(class_name).hash_code(), \
      #class_name, \
      typeid(class_name).name(), \
      typeid(class_name).raw_name(), \
      sizeof(class_name), \
      __VA_ARGS__, \
  }
