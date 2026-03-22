#include <iostream>

class Point {
private:
    double x;
    double y;

public:
    Point(double xInput = 0.0, double yInput = 0.0);

    double returnsX() const;
    double returnsY() const;

    //overloads
    double operator-(Point operatee) const;
    bool operator==(Point operatee) const;
    bool operator!=(Point operatee) const;
    Point operator/(Point operatee) const;

    // Add-on: scalar multiplication
    Point operator*(double scalar) const;

    // Add-on: indexing
    double operator[](char coord) const;

    // Friend for output streaming
    friend std::ostream& operator<<(std::ostream& os, Point p);
};
