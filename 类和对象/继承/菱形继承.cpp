#include <iostream>
using namespace std;

/*
菱形继承概念：
​ 两个派生类继承同一个基类
​ 又有某个类同时继承者两个派生类
​ 这种继承被称为菱形继承，或者钻石继承

菱形继承问题：
羊继承了动物的数据，驼同样继承了动物的数据，当草泥马使用数据时，就会产生二义性。
草泥马继承自动物的数据继承了两份，其实我们应该清楚，这份数据我们只需要一份就可以。
*/

class Animal
{
public:
    int m_age;
};
// 利用虚继承解决菱形继承的问题
// 这样Ainmal为虚基类 会有一个虚基类指针去指向基类的属性
class Sheep : virtual public Animal
{
};
class Camel : virtual public Animal
{
};
class SheepCamel : public Sheep, public Camel
{
};
void test01()
{
    SheepCamel sc;
    sc.Sheep::m_age = 10;
    sc.Camel::m_age = 20;
    // 菱形继承时，两个父类用于相同数据，需要加以作用域区分
    cout << "sc.Sheep::m_age = " << sc.Sheep::m_age << endl;
    cout << "sc.Camel::m_age = " << sc.Camel::m_age << endl;
    cout << "sc.m_ge = " << sc.m_age << endl;
    // 这份数据只有一份就行了，菱形继承导致数据有两份，资源浪费
}
int main()
{
    test01();
    return 0;
}
