#ifndef RVECTOR_HPP
#define RVECTOR_HPP

#include "Point.hpp"

class Rvector : public Point {
	public:
		Rvector(const Point& a, const Point& b);
		double length();
};
double crossProduct(const Rvector& a, const Rvector& b);
double scalarProduct(const Rvector& a, const Rvector& b);
double cosVec(Rvector& a, Rvector& b);

#endif // RVECTOR_HPP
