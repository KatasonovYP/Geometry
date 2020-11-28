#include "Circle.hpp"

// setters
void Circle::setCenter(const Point &_center) {
    center = _center;
}
void Circle::setRadius(double _radius) {
    radius = _radius;
}
// getters
Point Circle::getCenter() const {
    return center;
}
double Circle::getRadius() const {
    return radius;
}
// methods
double Circle::length() const {
    return 2 * M_PI * radius;
}
double Circle::area() const {
    return M_PI * radius * radius;
}

// functions
double distanceFromPointToCircle(const Point& a, const Circle& b) {
	return length(a, b.getCenter()) - b.getRadius();
}
