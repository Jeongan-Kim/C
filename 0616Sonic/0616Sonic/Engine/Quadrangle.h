#pragma once

#include "Point.h"

class Quadrangle
{
public:
    Quadrangle();
    Quadrangle(Point const & length, Point const & center);

public:
    Point Length = Point(1, 1); //x와 y에 대한 길이
    Point Center = Point(0, 0); //중점
};