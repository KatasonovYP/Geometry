#include <iostream>
#include "Point.hpp"

int main() {
    Point a(0, 0), b(1, 1);
    std::cout << "It's work! \nMaybe right, i hope...\n\n";
    std::cout << length(a, b);
    return 0;
}
