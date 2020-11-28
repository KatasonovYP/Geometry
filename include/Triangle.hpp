#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include <algorithm>
#include "Segment.hpp"

class Triangle {
	private:
		Point a, b, c;
		double sideA = length(b, c);
		double sideB = length(a, c);
		double sideC = length(a, b);
	public:
		Triangle(const Point& a, const Point& b, const Point& c) : a(a), b(b), c(c) {}
		void setA(const Point& _a);
		void setB(const Point& _b);
		void setC(const Point& _c);
		Point getA() const;
		Point getB() const;
		Point getC() const;
		double perimeter();
		double signArea();
		double area();
};
double distanceFromPointToTriangle(const Point& a, const Triangle& t);

#endif // TRIANGLE_HPP
