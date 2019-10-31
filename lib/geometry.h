#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <iostream>

struct Point {
	double x, y;

	Point();
	Point(double x, double y);

	Point floor();
};

Point operator+(const Point& p1, const Point& p2);
Point operator-(const Point& p1, const Point& p2);
Point operator*(const Point& p1, const Point& p2);
Point operator/(const Point& p1, const Point& p2);
Point operator*(const Point& p1, const double n);
Point operator/(const Point& p1, const double n);
Point operator*(const double n, const Point& p1);
Point operator/(const double n, const Point& p1);
Point operator-(const Point& p1);
std::ostream& operator<< (std::ostream& out, Point const& p);

#endif