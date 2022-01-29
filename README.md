# chiisai
chiisai is a simple header-only C++20 library for my own projects.

# Features
- Class reflection with members via `type_info`

# Building the example
```bash
clang++ $(sed -z 's/\n/ /g' compile_flags.txt) example/main.cpp
```
