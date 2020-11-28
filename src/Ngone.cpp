#include "Ngone.hpp"


// setters
void Ngone::setList(const std::vector <Point> & _x) {
    vertex = _x;
}
//getters
std::vector <Point> Ngone::getList() const {
    return vertex;
}
Point Ngone::getVertex(int n) const {
    return vertex[n];
}
int Ngone::getSize() const {
    return vertex.size();
}
// methods
double Ngone::perimeter() {
    double p = length(vertex.front(), vertex.back());
    for(int i = 0; i < vertex.size() - 1; i++){
        p += length(vertex[i], vertex[i + 1]);
    }
    return p;
}
double Ngone::area() {
    double sum = 0;
    Point z(0, 0);
    for(int i = 0; i < vertex.size(); i++) {
        Triangle x(vertex[i], vertex[(i + 1) % vertex.size()], z);
        sum += x.signArea();
    }
    return sum;
}

// function
double distanceFromPointToNgone (const Point& a, const Ngone& n) {
	double min = 1e9;
	int minIt = 0;
	int size = n.getSize();
	for(int i = 0; i < size; i++) {
		double t = length(a, n.getVertex(i));
		if(min > t) {
			min = t;
			minIt = i;
		}
	}
	double distanceX = distanceFromPointToSegment(a, Segment(n.getVertex(minIt), n.getVertex((minIt + 1) % size)));
	double distanceY = distanceFromPointToSegment(a, Segment(n.getVertex(minIt), n.getVertex((minIt - 1 + size) % size)));
	double distance = std::min(distanceX, distanceY);
	return std::abs(distance);
}
