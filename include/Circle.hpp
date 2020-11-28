#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "Point.hpp"

class Circle {
	private:
		Point center;
		double radius;
	public:
		// constructors
		Circle(const Point &o, double r): center(o), radius(r) {}
		// setters
		void setCenter(const Point &_center);
		void setRadius(double _radius);
		// getters
		Point getCenter() const;
		double getRadius() const;
		// methods
		double length() const;
		double area() const;
};

double distanceFromPointToCircle(const Point& a, const Circle& b);

#endif // CIRCLE_HPP
