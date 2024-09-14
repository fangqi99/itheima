#include <iostream>
using namespace std;

class Building
{

    // 告诉编译器 goodGuy全局函数 是 Building类的好朋友，可以访问类中的私有内容
    friend void goodGuy(Building *building);
    friend void goodGuy1(Building &building);

public:
    Building()
    {
        m_SittingRoom = "客厅";
        m_BedRoom = "卧室";
    }
    string m_SittingRoom; // 客厅

private:
    string m_BedRoom; // 卧室
};

void goodGuy(Building *building)
{
    cout << "好基友全局函数正在访问" << building->m_SittingRoom << endl;
    cout << "好基友全局函数正在访问" << building->m_BedRoom << endl;
}
// 两种写法
void goodGuy1(Building &building)
{
    cout << "好基友全局函数正在访问" << building.m_SittingRoom << endl;
    cout << "好基友全局函数正在访问" << building.m_BedRoom << endl;
}
void test01()
{
    Building b;
    goodGuy(&b);
    goodGuy1(b);
}
int main()
{
    test01();
    return 0;
}