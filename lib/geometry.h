#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <iostream>

struct Pointd {
	double x, y;
};

struct Pointi {
	int x, y;
};

inline
std::ostream& operator<< (std::ostream& out, Pointi const& point) {
	out << "(" << point.x << ", " << point.y << ")";
	return out;
}

inline
std::ostream& operator<< (std::ostream& out, Pointd const& point) {
	out << "(" << point.x << ", " << point.y << ")";
	return out;
}

#endif