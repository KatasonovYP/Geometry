#include "Ngone.hpp"

namespace Geometry {

    // setters
    void Ngone::set_list(const std::vector <Point> & _x) {
        vertex = _x;
    }

    // getters
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
        for(size_t i = 0; i < vertex.size() - 1; i++){
            p += length(vertex[i], vertex[i + 1]);
        }
        return p;
    }

    double Ngone::area() {
        double sum = 0;
        Point z(0, 0);
        for(size_t i = 0; i < vertex.size(); i++) {
            Triangle x(vertex[i], vertex[(i + 1) % vertex.size()], z);
            sum += x.sign_area();
        }
        return sum;
    }

    const bool cw(const Point& a, const Point& b, const Point& c) {
        return Triangle(a, b, c).sign_area() < 0;
    }

    const bool ccw(const Point& a, const Point& b, const Point& c) {
        return Triangle(a, b, c).sign_area() > 0;
    }

    bool Ngone::is_convex_hull() {
        Point p1 = vertex.front(), p2 = vertex.back();
        std::vector <Point> up, down;
        up.push_back(p1);
        down.push_back(p2);
        for (size_t i = 1; i < vertex.size(); ++i) {
            if(i == vertex.size() - 1 || cw(p1, vertex[i], p2)) {
                if(up.size() >= 2 && !cw(up[up.size() - 2], up[up.size() - 1], vertex[i]))
                    return false;
            }
            if(i == vertex.size() - 1 || ccw(p1, vertex[i], p2)) {
                if(down.size() >= 2 && !ccw(down[down.size() - 2], down[down.size() - 1], vertex[i]))
                    return false;
            }
        }
        return true;
    }

    void Ngone::convex_hull() {
        if(vertex.size() == 1){
            return;
        }
        std::sort(vertex.begin(), vertex.end(), [](const Point& a, const Point& b) {
                return a.x < b.x || (a.x == b.x && a.y < b.y);
            });
        Point p1 = vertex.front(), p2 = vertex.back();
        std::vector <Point> up, down;
        up.push_back(p1);
        down.push_back(p2);
        for (size_t i = 1; i < vertex.size(); ++i) {
            if (i == vertex.size() - 1 || cw(p1, vertex[i], p2)) {
                while (up.size() >= 2 && !cw(up[up.size() - 2], up[up.size() - 1], vertex[i]))
                    up.pop_back();
                up.push_back(vertex[i]);
            }
            if (i == vertex.size() - 1 || ccw (p1, vertex[i], p2)) {
                while (down.size() >= 2 && !ccw (down[down.size() - 2], down[down.size() - 1], vertex[i]))
                    down.pop_back();
                down.push_back(vertex[i]);
            }
        }
        vertex.clear();
        for(size_t i = 0; i < up.size(); ++i) {
            vertex.push_back(up[i]);
        }
        for(int i = down.size() - 2; i > 0; ++i) {
            vertex.push_back(down[i]);
        }
    }

    // functions
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

}
