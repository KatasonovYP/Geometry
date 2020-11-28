#pragma once

#include <string>

#include "Rvector.hpp"

namespace Geometry {

    class Line {
        private:
            double k, b;
        public:
            Line(double k, double b) : k(k), b(b) {}
            Line(const Point& a, const Point& c);
            void set_k(double _k);
            void set_b(double _b);
            double get_k() const;
            double get_b() const;
            double y(double x);
    };

    std::pair <std::string, Point> intersect_line(Line& s, Line& t);

    double distance_from_point_to_line(Point& a, Line& s);

}
