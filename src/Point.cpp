#include "Point.hpp"

double length (const Point& a, const Point& b) {
	double sideX = a.x - b.x;
	double sideY = a.y - b.y;
	return std::sqrt(sideX * sideX + sideY * sideY);
}
