#ifndef NGONE_HPP
#define NGONE_HPP

#include <vector>
#include "Triangle.hpp"

class Ngone{
	private:
		std::vector <Point> vertex;
	public:
		Ngone(const std::vector <Point>& x) : vertex(x) {}
		void setList(const std::vector <Point> & _x);
		std::vector <Point> getList() const;
		Point getVertex(int n) const;
		int getSize() const;
		double perimeter();
		double area();
};
double distanceFromPointToNgone (const Point& a, const Ngone& n);
#endif // NGONE_HPP
