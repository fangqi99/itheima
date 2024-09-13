#include <iostream>
using namespace std;

class Person
{
public:
    // Person()
    // {
    //     cout << "Person默认构造函数调用成功" << endl;
    // }
    // Person(int a)
    // {
    //     cout << "Person有参构造函数调用成功" << endl;
    //     m_A = a;
    // }
    Person(const Person &p) // 如果没有拷贝构造函数，编译器会默认生成一个拷贝构造函数来拷贝属性
    {
        cout << "Person拷贝构造函数调用成功" << endl;
        m_A = p.m_A;
    }
    ~Person()
    {
        cout << "Person析构函数调用成功" << endl;
    }
    int m_A;
};

// void test01()
// {
//     Person p1;
//     p1.m_A = 13;
//     Person p2(p1);
//     cout << p2.m_A << endl;
// }

void test02()
{
    // Person p1(10);
    // Person p2(p1);
    // cout << p2.m_A << endl;
}
void test03()
{
    // Person p1;
}
int main()
{
    // test01();
    test02();
    return 0;
}