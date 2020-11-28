#include "Rvector.hpp"

namespace Geometry {

    // constructors
    Rvector::Rvector(const Point& a, const Point& b) {
        x = (b.x - a.x);
        y = (b.y - a.y);
    }

    // metods
    double Rvector::length() {
        return std::sqrt(x * x + y * y);
    }

    // functions
    double cross_product(const Rvector& a, const Rvector& b) {
        return a.x * b.y - b.x * a.y;
    }

    double scalar_product(const Rvector& a, const Rvector& b) {
        return a.x * b.x + a.y * b.y;
    }

    double cos_vec(Rvector& a, Rvector& b) {
        return scalar_product(a, b) / (a.length() * b.length());
    }

    double angle(Rvector& a, Rvector& b) {
        return std::acos(cos_vec(a, b)) * 180. / M_PI;
    }

}
