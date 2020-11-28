#include "Rvector.hpp"

Rvector::Rvector(const Point& a, const Point& b) {
    x = (b.x - a.x);
    y = (b.y - a.y);
}

double Rvector::length() {
    return std::sqrt(x * x + y * y);
}

double crossProduct(const Rvector& a, const Rvector& b) {
	return a.x * b.y - b.x * a.y;
}
double scalarProduct(const Rvector& a, const Rvector& b) {
	return a.x * b.x + a.y * b.y;
}
double cosVec(Rvector& a, Rvector& b) {
	return scalarProduct(a, b) / (a.length() * b.length());
}
