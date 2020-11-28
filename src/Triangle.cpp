#include "Triangle.hpp"

// setters
void Triangle::setA(const Point& _a) {
    a = _a;
}
void Triangle::setB(const Point& _b) {
    b = _b;
}
void Triangle::setC(const Point& _c) {
    c = _c;
}
// getters
Point Triangle::getA() const {
    return a;
}
Point Triangle::getB() const {
    return b;
}
Point Triangle::getC() const {
    return c;
}
// methods
double Triangle::perimeter() {
    return sideA + sideB + sideC;
}
double Triangle::signArea() {
    Rvector ab(a, b), ac(a, c);
    return crossProduct(ab, ac) / 2;
}
double Triangle::area() {
    return std::abs(signArea());
}

// functions
double distanceFromPointToTriangle(const Point& a, const Triangle& t) {
	double distanceX = distanceFromPointToSegment(a, Segment(t.getA(), t.getB()));
	double distanceY = distanceFromPointToSegment(a, Segment(t.getB(), t.getC()));
	double distanceZ = distanceFromPointToSegment(a, Segment(t.getA(), t.getC()));
	return std::min(distanceX, std::min(distanceY, distanceZ));
}
