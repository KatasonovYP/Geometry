#include "Segment.hpp"

// setters
void Segment::setPointA(const Point& _a) {
    a = _a;
}
void Segment::setPointB(const Point& _b) {
    b = _b;
}

// getters
Point Segment::getPointA() const {
    return a;
}
Point Segment::getPointB() const {
    return b;
}

// methods
double Segment::length() {
    double sideX = a.x - b.x;
    double sideY = a.y - b.y;
    return std::sqrt(sideX * sideX + sideY * sideY);
}

double distanceFromPointToSegment (const Point& c, const Segment& s) {
	double distance;
	Rvector ac(s.getPointA(), c);
	Rvector bc(s.getPointB(), c);
	Rvector ab(s.getPointA(), s.getPointB());
	Rvector ba(s.getPointB(), s.getPointA());

	if(scalarProduct(ac, ab) <= 0){
		distance = ac.length();
	}
	else if(scalarProduct(bc, ba) <= 0) {
		distance = bc.length();
	}
	else if(crossProduct(ac, ab) == 0) {
		distance = 0;
	}
	else {
		distance = crossProduct(ac, ab) / ab.length();
	}
	return std::abs(distance);
}
