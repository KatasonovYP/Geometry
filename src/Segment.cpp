#include "Segment.hpp"

// setters
void Segment::set_point_a(const Point& _a) {
    a = _a;
}

void Segment::set_point_b(const Point& _b) {
    b = _b;
}

// getters
Point Segment::get_point_a() const {
    return a;
}

Point Segment::get_point_b() const {
    return b;
}

// methods
double Segment::length() {
    double side_x = a.x - b.x;
    double side_y = a.y - b.y;
    return std::sqrt(side_x * side_x + side_y * side_y);
}

double distance_from_point_to_segment(const Point& c, const Segment& s) {
	double distance;
	Rvector ac(s.get_point_a(), c);
	Rvector bc(s.get_point_b(), c);
	Rvector ab(s.get_point_a(), s.get_point_b());
	Rvector ba(s.get_point_b(), s.get_point_a());

	if(scalar_product(ac, ab) <= 0){
		distance = ac.length();
	}
	else if(scalar_product(bc, ba) <= 0) {
		distance = bc.length();
	}
	else if(cross_product(ac, ab) == 0) {
		distance = 0;
	}
	else {
		distance = cross_product(ac, ab) / ab.length();
	}
	return std::abs(distance);
}
