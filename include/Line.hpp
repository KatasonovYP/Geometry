#pragma once

#include "Segment.hpp"

class Line {
	private:
		double k, b;
	public:
		Line(double k, double b) : k(k), b(b) {}
		Line(const Point& a, const Point& c);
		Line(const Segment& s);
		void set_k(double _k);
		void set_b(double _b);
		double get_k() const;
		double get_b() const;
		double y(double x);
};
