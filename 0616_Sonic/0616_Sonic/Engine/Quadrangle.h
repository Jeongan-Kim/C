#pragma once

#include "Point.h"

class Quadrangle
{
public:
    Quadrangle();
    Quadrangle(Point const & length, Point const & center);

public:
    Point Length = Point(1, 1); //x�� y�� ���� ����
    Point Center = Point(0, 0); //����
};