#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"
#include <cstdlib>
#include<fstream>
#include<iostream>
#include<cmath>

using Color = Vec3;

inline Color lerp_colors(double a, Color start, Color end){
  return start * (1.0 - a) + end * a;
}

inline void write_colors(const char pixel_colors[], int WIDTH, int HEIGHT){
  // Write to file
  std::ofstream filp("../../renders/image.ppm");
  if (!filp){
    std::cerr << "Error opening the file" << std::endl;
    exit(1);
  }

  filp.write(pixel_colors, WIDTH * HEIGHT * sizeof(char));
}

#endif
