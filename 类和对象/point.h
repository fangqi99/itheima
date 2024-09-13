#pragma once
#include <iostream>
using namespace std;

class Point
{
public:
    // 设置点的坐标
    void setPoint(int x, int y);

    int getPointX();

    int getPointY();

private:
    // 设置点的位置坐标
    int m_x, m_y;
};