#include "Circle.hpp"

// setters
void Circle::set_center(const Point &_center) {
    center = _center;
}

void Circle::set_radius(double _radius) {
    radius = _radius;
}

// getters
Point Circle::get_center() const {
    return center;
}

double Circle::get_radius() const {
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
double distance_from_point_to_circle(const Point& a, const Circle& b) {
	return length(a, b.get_center()) - b.get_radius();
}
