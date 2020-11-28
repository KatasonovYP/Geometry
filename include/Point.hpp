#pragma once

#include <cmath>
#include <utility>
#include <vector>

class Point {
    public:
	int x, y;
	Point(int x, int y): x(x), y(y) {}
	Point() = default;
};

double length(const Point& a, const Point& b);

std::pair <Point, Point> find_pair_nearest(std::vector <Point> &x);
