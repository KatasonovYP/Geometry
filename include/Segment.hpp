#ifndef SEGMENT_HPP
#define SEGMENT_HPP

#include "Rvector.hpp"

class Segment {
	private:
		Point a, b;
	public:
		Segment(const Point& a, const Point& b) : a(a), b(b) {}
		Segment() = default;
		void setPointA(const Point& _a);
		void setPointB(const Point& _b);
		Point getPointA() const;
		Point getPointB() const;
		double length();
};

double distanceFromPointToSegment (const Point& c, const Segment& s);

#endif // SEGMENT_HPP
