#pragma once

#include "Point.hpp"

class Circle {
	private:
		Point center;
		double radius;
	public:
		Circle(const Point &o, double r): center(o), radius(r) {}
		void set_center(const Point &_center);
		void set_radius(double _radius);
		Point get_center() const;
		double get_radius() const;
		double length() const;
		double area() const;
};

double distance_from_point_to_circle(const Point& a, const Circle& b);
