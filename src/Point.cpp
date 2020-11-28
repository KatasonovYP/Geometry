#include "Point.hpp"

double length (const Point& a, const Point& b) {
	double sideX = a.x - b.x;
	double sideY = a.y - b.y;
	return std::sqrt(sideX * sideX + sideY * sideY);
}

std::pair <Point, Point> find_pair_nearest(std::vector <Point> &x) {
    double min = 1e9;
    std::pair <Point, Point> near;
    for(const auto& it : x) {
        for(const auto& jt : x) {
            if(length(it, jt) < min) {
                min = length(it, jt);
                near = std::make_pair(it, jt);
            }
        }
    }
    return near;
}
