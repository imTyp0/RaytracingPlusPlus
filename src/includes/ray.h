#ifndef RAY_H
#define RAY_H

#include "vec3.h"

struct Ray{
  Vec3 origin;
  Vec3 direction;

  // Constructor
  Ray(Vec3 o, Vec3 d) : origin(o), direction(d){}

  // Functions
  Vec3 at(double t){
    return direction * t + origin;
  }
};

#endif
