#pragma once

#include "Line.hpp"

namespace Geometry {

    class Segment {
        private:
            Point a, b;
        public:
            Segment(const Point& a, const Point& b) : a(a), b(b) {}
            Segment() = default;
            void set_point_a(const Point& _a);
            void set_point_b(const Point& _b);
            Point get_point_a() const;
            Point get_point_b() const;
            double length();
    };

    Line make_line(const Segment& s);

    double distance_from_point_to_segment(const Point& c, const Segment& s);

}
