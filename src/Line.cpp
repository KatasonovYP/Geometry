#include "Line.hpp"

namespace Geometry {

    // constructors
    Line::Line(const Point& a, const Point& c) {
        if (std::abs(a.y - c.y) <= EPS) {
            k = 0;
        } else {
            k = (a.y - c.y) / (a.x - c.x);
        }
        b = a.y - k * a.x;
    }

    Line::Line(const Segment& s) {
        k = (s.get_point_a().y - s.get_point_b().y) / (s.get_point_a().x - s.get_point_b().x);
        b = s.get_point_a().y - k * s.get_point_b().x;
    }

    // setter
    void Line::set_k(double _k) {
        k = _k;
    }

    void Line::set_b(double _b) {
        b = _b;
    }

    // getter
    double Line::get_k() const {
       return k;
    }

    double Line::get_b() const {
        return b;
    }

    // methods
    double Line::y(double x) {
        return k * x + b;
    }

    // functions
    std::pair <std::string, Point> intersect_line(Line& s, Line& t) {
        std::pair <std::string, Point> solution;
        if(std::abs(s.get_k() - t.get_k()) <= EPS) {
            if(std::abs(s.get_b() - t.get_b()) <= EPS) {
                solution = std::make_pair("inf", Point());
            } else {
                solution = std::make_pair("no roots", Point());
            }
        } else {
            double x = (t.get_b() - s.get_b()) / (s.get_k() - t.get_k());
            solution = std::make_pair("one root", Point(x, s.y(x)));
        }
        return solution;
    }

    double distance_from_point_to_line(Point& a, Line& s) {
        Point b(0, s.y(0));
        Point c(1, s.y(1));
        Rvector ab(a, b);
        Rvector ac(a, c);
        return std::abs(cross_product(ac, ab) / ab.length());
    }

}
