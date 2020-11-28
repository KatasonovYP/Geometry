#pragma once

#include <algorithm>

#include "Segment.hpp"

class Triangle {
	private:
		Point a, b, c;
		double side_a = length(b, c);
		double side_b = length(a, c);
		double side_c = length(a, b);
	public:
		Triangle(const Point& a, const Point& b, const Point& c) : a(a), b(b), c(c) {}
		void set_a(const Point& _a);
		void set_b(const Point& _b);
		void set_c(const Point& _c);
		Point get_a() const;
		Point get_b() const;
		Point get_c() const;
		double perimeter();
		double sign_area();
		double area();
};

double distance_from_point_to_triangle(const Point& a, const Triangle& t);
