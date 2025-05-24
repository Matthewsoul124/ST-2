// Copyright 2022 UNN-CS
#include "circle.h"
#include <cmath>
#include <cstdint>
#include <stdexcept>

const double PI = 3.14159265358979323846;

Circle::Circle(double radius) { setRadius(radius); }

void Circle::setRadius(double radius) {
  if (radius < 0) {
    throw std::invalid_argument("Radius cannot be negative");
  }
  this->radius = radius;
  calculateFerence();
  calculateArea();
}

void Circle::setFerence(double ference) {
  if (ference < 0) {
    throw std::invalid_argument("Ference cannot be negative");
  }
  this->ference = ference;
  calculateRadius();
  calculateArea();
}

void Circle::setArea(double area) {
  if (area < 0) {
    throw std::invalid_argument("Area cannot be negative");
  }
  this->area = area;
  this->radius = sqrt(area / PI);
  calculateFerence();
}

double Circle::getRadius() const { return radius; }

double Circle::getFerence() const { return ference; }

double Circle::getArea() const { return area; }

void Circle::calculateFerence() { ference = 2 * PI * radius; }

void Circle::calculateArea() { area = PI * radius * radius; }

void Circle::calculateRadius() { radius = ference / (2 * PI); }
