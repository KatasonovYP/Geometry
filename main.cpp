#include <iostream>

#include "Line.hpp"

int main() {
    Geometry::Point a(0, 0), b(1, 2), c(2, 1), d(10, 2);
    Geometry::Line ab(a, b), ac(c, d);
    std::cout << "It's work! \nMaybe right, i hope...\n\n";
    std::cout << intersect_line(ab, ac).first << '\n' << intersect_line(ab, ac).second.x << ' ' << intersect_line(ab, ac).second.y;
    return 0;
}
