#include <cmath>
#include "point.hpp"

Point::Point(double xInput, double yInput) {
    x = xInput;
    y = yInput;
}

double Point::returnsX() const {
    return x;
}

double Point::returnsY() const {
    return y;
}

double Point::operator-(Point operatee) const {
    return std::sqrt(std::pow(operatee.x - x, 2) + std::pow(operatee.y - y, 2));
}

bool Point::operator==(Point operatee) const {
    return (x == operatee.x) && (y == operatee.y);
}

bool Point::operator!=(Point operatee) const {
    return !(*this == operatee);
}

Point Point::operator/(Point operatee) const {
    return Point((x + operatee.x) / 2.0, (y + operatee.y) / 2.0);
}

Point Point::operator*(double scalar) const {
    return Point(x * scalar, y * scalar);
}

double Point::operator[](char coord) const {
    if (coord == 'x' || coord == 'X') {
        return x;
    } else if (coord == 'y' || coord == 'Y') {
        return y;
    } else {
        throw std::invalid_argument("Invalid index. Use 'x' or 'y'.");
    }
}

std::ostream& operator<<(std::ostream& os, Point p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}
