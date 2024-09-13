#include <iostream>
using namespace std;

class Cube
{
public:
    void setLength(double len)
    {
        length = len;
    }
    double getLength()
    {
        return length;
    }

    void setWidth(double wid)
    {
        width = wid;
    }
    double getWidth()
    {
        return width;
    }

    void setHeight(double hei)
    {
        height = hei;
    }
    double getHeight()
    {
        return height;
    }
    double getVolume()
    {
        return length * width * height;
    }
    double getEarth()
    {
        return 2 * (length * width + length * height + width * height);
    }
    bool isSameByClass(Cube &cube)
    {
        return (length == cube.getLength() && width == cube.getWidth() && height == cube.getHeight()); // 自身的和传进来的判断
    }

private:
    double length;
    double width;
    double height;
};
// 全局函数判断是否相等
bool isSame(Cube &cube1, Cube &cube2) // 引用的方式传递--用原始数据
{
    if (cube1.getLength() == cube2.getLength() && cube1.getWidth() == cube2.getWidth() && cube1.getHeight() == cube2.getHeight())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    Cube cube1;
    cube1.setHeight(10);
    cube1.setLength(10);
    cube1.setWidth(10);
    cube1.getVolume();
    cout << "cube1 体积为：" << cube1.getVolume() << endl;
    cube1.getEarth();
    cout << "cube1表面积为：" << cube1.getEarth() << endl;
    Cube cube2;
    cube2.setHeight(10);
    cube2.setLength(10);
    cube2.setWidth(10);
    cube2.getVolume();
    cout << "cube2 体积为：" << cube2.getVolume() << endl;
    cube2.getEarth();
    cout << "cube2表面积为：" << cube2.getEarth() << endl;

    isSame(cube1, cube2);
    if (isSame(cube1, cube2))
    {
        cout << "两个立方体相等" << endl;
    }
    else
    {
        cout << "两个立方体不相等" << endl;
    }
    bool ret = cube1.isSameByClass(cube2);
    if (ret)
    {
        cout << "类内判断两个立方体相等" << endl;
    }
    else
    {
        cout << "类内两个立方体不相等" << endl;
    }
    return 0;
}