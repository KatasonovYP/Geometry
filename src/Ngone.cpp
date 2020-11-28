#include "Ngone.hpp"


// setters
void Ngone::set_list(const std::vector <Point> & _x) {
    vertex = _x;
}

//getters
std::vector <Point> Ngone::get_list() const {
    return vertex;
}

Point Ngone::get_vertex(int n) const {
    return vertex[n];
}

int Ngone::get_size() const {
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
        sum += x.sign_area();
    }
    return sum;
}

// function
double distanceFromPointToNgone (const Point& a, const Ngone& n) {
	double min = 1e9;
	int minIt = 0;
	int size = n.get_size();
	for(int i = 0; i < size; i++) {
		double t = length(a, n.get_vertex(i));
		if(min > t) {
			min = t;
			minIt = i;
		}
	}
	double distance_x = distance_from_point_to_segment(a, Segment(n.get_vertex(minIt), n.get_vertex((minIt + 1) % size)));
	double distance_y = distance_from_point_to_segment(a, Segment(n.get_vertex(minIt), n.get_vertex((minIt - 1 + size) % size)));
	double distance = std::min(distance_x, distance_y);
	return std::abs(distance);
}
