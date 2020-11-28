#ifndef STRAIGHT_HPP
#define STRAIGHT_HPP

#include "Segment.hpp"

class Straight {
	private:
		double k, b;
	public:
		Straight(double k, double b) : k(k), b(b) {}
		Straight(const Point& a, const Point& c);
		Straight(const Segment& s);
		void setK(double _k);
		void setB(double _b);
		double getK() const;
		double getB() const;
		double y(double x);
};
Point intersectStraight(Straight& s, Straight& t);
double distanceFromPointToStraight (Point& a, Straight& s);

#endif // STRAIGHT_HPP
