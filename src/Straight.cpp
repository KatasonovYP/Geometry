#include "Straight.hpp"

// constructors
Straight::Straight(const Point& a, const Point& c) {
    k = (a.y - c.y) / (a.x - c.x);
    b = a.y - k * c.x;
}
Straight::Straight(const Segment& s) {
    k = (s.getPointA().y - s.getPointB().y) / (s.getPointA().x - s.getPointB().x);
    b = s.getPointA().y - k * s.getPointB().x;
}
// setter
void Straight::setK(double _k) {
    k = _k;
}
void Straight::setB(double _b) {
    b = _b;
}
// getter
double Straight::getK() const {
    return k;
}
double Straight::getB() const {
    return b;
}
// methods
double Straight::y(double x) {
    return k * x + b;
}

// functions

Point intersectStraight(Straight& s, Straight& t) {
	double x = (t.getB() - s.getB()) / (s.getK() - t.getK());
	Point i(x, s.y(x));
	return i;
}
double distanceFromPointToStraight (Point& a, Straight& s) {
	double distance;
	Point b(0, s.y(0));
	Point c(1, s.y(1));
	Rvector ac(a, c);
	Rvector ab(a, b);
	if(crossProduct(ac, ab) == 0) {
		distance = 0;
	}
	else {
		distance = crossProduct(ac, ab) / ab.length();
	}
	return std::abs(distance);
}
