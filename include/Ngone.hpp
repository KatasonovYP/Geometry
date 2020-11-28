#pragma once

#include <vector>

#include "Triangle.hpp"

class Ngone{
	private:
		std::vector <Point> vertex;
	public:
		Ngone(const std::vector <Point>& x) : vertex(x) {}
		void set_list(const std::vector <Point> & _x);
		std::vector <Point> get_list() const;
		Point get_vertex(int n) const;
		int get_size() const;
		double perimeter();
		double area();
};

double distance_from_point_to_ngone(const Point& a, const Ngone& n);
