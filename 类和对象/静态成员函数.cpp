#include <iostream>
using namespace std;

class Person
{
public:
    // 静态成员函数特点：
    // 1 程序共享一个函数
    // 2 静态成员函数只能访问静态成员变量
    static void func() // 静态成员函数
    {
        m_A = 100; // 静态成员函数只能访问静态成员变量
        // m_B = 200; ////错误，不可以访问非静态成员变量
        cout << "static func的调用" << endl;
    }
    static int m_A; /// 静态成员变量
    int m_B;        // 非静态成员变量
private:
    // 静态成员函数也是有访问权限的
    static void func2()
    {
        cout << "static func2调用" << endl;
    }
};
int Person::m_A = 100; // 静态成员变量初始化

void test01()
{
    // 静态成员变量两种访问方式

    // 1、通过对象
    Person p1;
    p1.func();

    // 2、通过类名
    Person::func();

    // Person::func2(); //私有权限类外访问不到
}

int main()
{
    test01();
    return 0;
}