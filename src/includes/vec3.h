#ifndef VEC3_H
#define VEC3_H

#include<cmath>
#include<random>

struct Vec3{
  double x;
  double y;
  double z;

  // Constructor
  Vec3(double x, double y, double z) : x(x), y(y), z(z) {}
  static Vec3 zero(){
    return Vec3(0,0,0);
  }

  // Functions
  double len_squared(){
    return x*x + y*y + z*z;
  }
  double len(){
    return std::sqrt(len_squared());
  }
  double dot(Vec3 b){
    return x*b.x + y*b.y + z*b.z;
  }
  Vec3 cross(Vec3 b){
    return Vec3(
      y * b.z - z * b.y,
      z * b.x - x * b.z,
      x * b.y - y * b.x
    );
  }
  void normalize(){
    double len = this->len();
      x /= len;
      y /= len;
      z /= len;
  }
  static Vec3 random_range(double min, double max){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> distribution(min, max);

    return Vec3(
      distribution(gen),
      distribution(gen),
      distribution(gen)
    );
  }
  bool near_zero(){
    const double EPS = 1e-8;
    return (std::abs(x) < EPS) && (std::abs(y) < EPS) && (std::abs(z) < EPS);
  }

  // Operators
  Vec3 operator-() const{
    return Vec3(-x, -y, -z);
  }
  Vec3 operator+(const Vec3& rhs) const{
    return Vec3(
      x + rhs.x,
      y + rhs.y,
      z + rhs.z
    );
  }
  Vec3 operator+(double rhs) const{
    return Vec3(
      x + rhs,
      y + rhs,
      z + rhs
    );
  }
  void operator+=(const Vec3& rhs){
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
  }
  Vec3 operator*(const Vec3& rhs) const{
    return Vec3(
      x * rhs.x,
      y * rhs.y,
      z * rhs.z
    );
  }
  Vec3 operator*(double rhs) const{
    return Vec3(
      x * rhs,
      y * rhs,
      z * rhs
    );
  }
  Vec3 operator/(double rhs) const{
    return Vec3(
      x / rhs,
      y / rhs,
      z / rhs
    );
  }
};
#endif
