#pragma once

#include "Point.hpp"

class Rvector : public Point {
	public:
		Rvector(const Point& a, const Point& b);
		double length();
};

double cross_product(const Rvector& a, const Rvector& b);

double scalar_product(const Rvector& a, const Rvector& b);

double cos_vec(Rvector& a, Rvector& b);
