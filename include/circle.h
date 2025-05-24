// Copyright 2022 UNN-CS
#ifndef CIRCLE_H
#define CIRCLE_H

class Circle {
private:
  double radius;
  double ference;
  double area;

  void calculateFerence();
  void calculateArea();
  void calculateRadius();

public:
  explicit Circle(double radius);

  void setRadius(double radius);
  void setFerence(double ference);
  void setArea(double area);

  double getRadius() const;
  double getFerence() const;
  double getArea() const;
};

#endif // CIRCLE_H
