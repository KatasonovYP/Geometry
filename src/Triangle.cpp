#include "Triangle.hpp"

// setters
void Triangle::set_a(const Point& _a) {
    a = _a;
}

void Triangle::set_b(const Point& _b) {
    b = _b;
}

void Triangle::set_c(const Point& _c) {
    c = _c;
}

// getters
Point Triangle::get_a() const {
    return a;
}

Point Triangle::get_b() const {
    return b;
}

Point Triangle::get_c() const {
    return c;
}

// methods
double Triangle::perimeter() {
    return side_a + side_b + side_c;
}

double Triangle::sign_area() {
    Rvector ab(a, b), ac(a, c);
    return cross_product(ab, ac) / 2;
}

double Triangle::area() {
    return std::abs(sign_area());
}

// functions
double distance_from_point_to_triangle(const Point& a, const Triangle& t) {
	double distance_x = distance_from_point_to_segment(a, Segment(t.get_a(), t.get_b()));
	double distance_y = distance_from_point_to_segment(a, Segment(t.get_b(), t.get_c()));
	double distance_z = distance_from_point_to_segment(a, Segment(t.get_a(), t.get_c()));
	return std::min(distance_x, std::min(distance_y, distance_z));
}
