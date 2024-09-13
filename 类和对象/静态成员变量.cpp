#include <iostream>
using namespace std;

class Person
{
public:
    // 静态成员变量特点：
    // 1 在编译阶段分配内存
    // 2 类内声明，类外初始化
    // 3 所有对象共享同一份数据
    static int m_A; // 静态成员变量  类内声明
private:
    static int m_B; // 静态成员变量也是有访问权限的
};
int Person::m_A = 10; // 类外初始化
int Person::m_B = 20;

void test01()
{
    // 静态成员变量两种访问方式

    // 1、通过对象
    Person p1;
    p1.m_A = 100;
    cout << "p1.m_A = " << p1.m_A << endl;

    Person p2;
    p2.m_A = 200;
    cout << "p1.m_A = " << p1.m_A << endl; // 共享同一份数据
    cout << "p2.m_A = " << p2.m_A << endl;

    // 2、通过类名
    cout << "m_A = " << Person::m_A << endl;

    // cout << "m_B = " << Person::m_B << endl; //私有权限访问不到
}
void test02()
{
    // 静态成员变量，不属于某个对象上，所有对象都共享
    // 因此有两个访问方式
    Person p1;
    cout << p1.m_A << endl;
    // 通过类名访问
    cout << Person::m_A << endl;
}
int main()
{
    test01();

    return 0;
}