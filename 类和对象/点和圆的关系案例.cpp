#include <iostream>
#include <cmath>
#include "Point.h"
using namespace std;

class Circle
{
public:
    void setCenter(Point &p)
    {
        m_center = p;
    }
    Point getCenter()
    {
        return m_center;
    }
    void setR(int r)
    {
        m_r = r;
    }
    int getR()
    {
        return m_r;
    }

private:
    int m_r;
    // 圆心坐标
    Point m_center;
};

double getDistance(Point &p, Circle &c)
{
    return sqrt((p.getPointX() - c.getCenter().getPointX()) * (p.getPointX() - c.getCenter().getPointX()) +
                (p.getPointY() - c.getCenter().getPointY()) * (p.getPointY() - c.getCenter().getPointY()));
}

int main()
{
    Point p1;
    Point center;
    p1.setPoint(1, 1);
    center.setPoint(10, 10);
    Circle c1;
    // c1.setCenter(center.setPoint(10, 10)); // 这样传入是（10，10）,而改函数只能解释Point类型的参数，所以要传一个Point类型的对象
    c1.setCenter(center);
    c1.setR(3);
    double distance = getDistance(p1, c1);
    cout << distance << endl;
    if (getDistance(p1, c1) < c1.getR())
    {
        cout << "点在圆内" << endl;
    }
    else if (getDistance(p1, c1) > c1.getR())
    {
        cout << "点在圆外" << endl;
    }
    else
    {
        cout << "点在圆上" << endl;
    }
    return 0;
}
