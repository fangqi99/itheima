#include <iostream>
using namespace std;

// 问题：当子类与父类出现同名的成员，如何通过子类对象，访问到子类或父类中同名的数据呢？

// 访问子类同名成员 直接访问即可
// 访问父类同名成员 需要加作用域

class Base
{
public:
    Base()
    {
        m_A = 100;
    }

    void func()
    {
        cout << "Base - func()调用" << endl;
    }

    void func(int a)
    {
        cout << "Base - func(int a)调用" << endl;
    }

public:
    int m_A;
};

class Son : public Base
{
public:
    Son()
    {
        m_A = 200;
    }

    // 当子类与父类拥有同名的成员函数，子类会隐藏父类中所有版本的同名成员函数
    // 如果想访问父类中被隐藏的同名成员函数，需要加父类的作用域
    void func()
    {
        cout << "Son - func()调用" << endl;
    }
    void func(int a)
    {
        cout << "Son - func(int a)调用" << endl;
    }

public:
    int m_A;
};

void test01()
{
    Son s;

    cout << "Son下的m_A = " << s.m_A << endl;
    cout << "Base下的m_A = " << s.Base::m_A << endl;

    s.func();
    s.func(100);
    s.Base::func();
    s.Base::func(10);
}
int main()
{

    test01();
    return 0;
}
/***
子类对象可以直接访问到子类中同名成员
子类对象加作用域可以访问到父类同名成员
当子类与父类拥有同名的成员函数，子类会隐藏父类中同名成员函数，加作用域可以访问到父类中同名函数
***/