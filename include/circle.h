// Copyright 2024 UNN-CS
#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_

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

#endif  // INCLUDE_CIRCLE_H_
