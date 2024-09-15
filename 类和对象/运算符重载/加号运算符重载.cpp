#include <iostream>
using namespace std;
// 实现两个自定义数据类型相加的运算
class Person
{
public:
    Person() {};         // 默认构造函数
    Person(int a, int b) // 有参构造
    {
        this->m_A = a;
        this->m_B = b;
    }
    // 成员函数实现 + 号运算符重载
    Person operator+(const Person &p)
    {
        Person pTemp;
        pTemp.m_A = this->m_A + p.m_A;
        pTemp.m_B = this->m_B + p.m_B;
        return pTemp;
    }
    int m_A;
    int m_B;
};

// 全局函数实现 + 号运算符重载
// Person operator+(const Person &p1, const Person &p2)
// {
//     Person pTemp;
//     pTemp.m_A = p1.m_A + p2.m_A;
//     pTemp.m_B = p1.m_B + p2.m_B;
//     return pTemp;
// }

// 运算符重载 可以发生函数重载
Person operator+(const Person &p1, int val) // operator+的函数重载 val 要加& 最好是接受变量 而不是字面量
{
    Person pTemp;
    pTemp.m_A = p1.m_A + val;
    pTemp.m_B = p1.m_B + val;
    return pTemp;
}
void test01()
{
    // int a=10;变量
    Person p1(10, 10);
    Person p2(20, 20);
    // 成员函数方式  p1.operator+(p2)
    Person p3 = p2 + p1; // 相当于 p2.operaor+(p1)
    cout << "mA:" << p3.m_A << " mB:" << p3.m_B << endl;
    Person p4 = p1 + 10;
    cout << "mA:" << p4.m_A << " mB:" << p4.m_B << endl;
}
int main()
{
    test01();
    return 0;
}