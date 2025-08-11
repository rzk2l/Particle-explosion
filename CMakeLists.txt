cmake_minimum_required(VERSION 3.10)

project(particleExplosion)

# SDL DIRECTORY
set(SDL3_DIR "C:/Rabah/9raya/C++/Libs/SDL3-devel-3.2.14-mingw/SDL3-3.2.14/x86_64-w64-mingw32")
include_directories(${SDL3_DIR}/include)
link_directories(${SDL3_DIR}/lib)


add_executable(particleExplosion main.cpp Screen.h Screen.cpp Particles.h Particles.cpp Swarm.h Swarm.cpp) 

# Link SDL3 library manually
target_link_libraries(particleExplosion SDL3)