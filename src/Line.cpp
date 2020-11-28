#include "Line.hpp"

// constructors
Line::Line(const Point& a, const Point& c) {
    k = (a.y - c.y) / (a.x - c.x);
    b = a.y - k * c.x;
}

Line::Line(const Segment& s) {
    k = (s.get_point_a().y - s.get_point_b().y) / (s.get_point_a().x - s.get_point_b().x);
    b = s.get_point_a().y - k * s.get_point_b().x;
}

// setter
void Line::set_k(double _k) {
    k = _k;
}

void Line::set_b(double _b) {
    b = _b;
}

// getter
double Line::get_k() const {
   return k;
}

double Line::get_b() const {
    return b;
}

// methods
double Line::y(double x) {
    return k * x + b;
}

// functions
Point intersect_line(Line& s, Line& t) {
	double x = (t.get_b() - s.get_b()) / (s.get_k() - t.get_k());
	Point i(x, s.y(x));
	return i;
}

double distance_from_point_to_line(Point& a, Line& s) {
	double distance;
	Point b(0, s.y(0));
	Point c(1, s.y(1));
	Rvector ac(a, c);
	Rvector ab(a, b);
	if(cross_product(ac, ab) == 0) {
		distance = 0;
	}
	else {
		distance = cross_product(ac, ab) / ab.length();
	}
	return std::abs(distance);
}
