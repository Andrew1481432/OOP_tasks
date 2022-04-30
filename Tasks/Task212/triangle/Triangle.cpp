#include "Triangle.h"
#include <cmath>

Triangle::Triangle(int a, int b, int c) {
    this->A = a;
    this->B = b;
    this->C = c;
}

int Triangle::per() {
    return A + B + C;
}

double Triangle::square() {
    double halfPer = this->per() / 2.0;
    double square = sqrt(halfPer * (halfPer - A) * (halfPer - B) * (halfPer - C)); // формула Герона
    return square;
}