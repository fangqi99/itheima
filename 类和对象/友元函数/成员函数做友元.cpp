#include <iostream>
using namespace std;

class Building;
class GoodGuy
{
public:
    GoodGuy();
    void visit();
    void visit2();
    Building *building;
};
class Building
{
    // 告诉编译器  goodGay类中的visit成员函数 是Building好朋友，可以访问私有内容
    friend void GoodGuy::visit();

public:
    Building();
    string m_SittingRoom;

private:
    string m_BedRoom;
};

// 类外实现成员函数
Building::Building()
{
    m_SittingRoom = "客厅";
    m_BedRoom = "卧室";
}
GoodGuy::GoodGuy()
{
    building = new Building;
}
void GoodGuy::visit()
{
    cout << "好基友visit正在访问" << building->m_SittingRoom << endl; // 公共内容
    cout << "好基友visit正在访问" << building->m_BedRoom << endl;     // 私有内容
}

void GoodGuy::visit2()
{
    cout << "好基友visit2正在访问" << building->m_SittingRoom << endl;
    // cout << "好基友visit2正在访问" << building->m_BedRoom << endl;
}
void test01()
{
    GoodGuy goodguy;
    goodguy.visit();
    goodguy.visit2();
}
int main()
{
    test01();
    return 0;
}