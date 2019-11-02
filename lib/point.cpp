#include "point.h"

Point::Point() {
	this->x = 0;
	this->y = 0;
}

Point::Point(double x, double y) {
	this->x = x;
	this->y = y;
}

Point Point::floor() {
	return Point((int)x, (int)y);
}

Point operator+(const Point& p1, const Point& p2) {
	return Point(p1.x + p2.x, p1.y + p2.y);
}

Point operator-(const Point& p1, const Point& p2) {
	return Point(p1.x - p2.x, p1.y - p2.y);
}

Point operator*(const Point& p1, const Point& p2) {
	return Point(p1.x * p2.x, p1.y * p2.y);
}

Point operator/(const Point& p1, const Point& p2) {
	return Point(p1.x / p2.x, p1.y / p2.y);
}

Point operator/(const Point& p1, const double n) {
	return Point(p1.x / n, p1.y / n);
}

Point operator*(const Point& p1, const double n) {
	return Point(p1.x * n, p1.y * n);
}

Point operator*(const double n, const Point& p1) {
	return Point(p1.x * n, p1.y * n);
}

Point operator/(const double n, const Point& p1) {
	return Point(n / p1.x, n / p1.y);
}

Point operator-(const Point& p1) {
	return Point(-p1.x, -p1.y);
}

std::ostream& operator<< (std::ostream& out, Point const& p) {
	out << "(" << p.x << ", " << p.y << ")";
	return out;
}