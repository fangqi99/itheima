#include <iostream>
using namespace std;
// 初始列表
class Person
{
public:
    // 传统初始化
    Person(int a, int b, int c)
    {
        m_A = a;
        m_B = b;
        m_C = c;
    }
    // 初始化列表方式初始化
    Person(int a, int b, int c) : m_A(a), m_B(b), m_C(c) {};
    void PersonPrint()
    {
        cout << m_A << endl;
        cout << m_B << endl;
        cout << m_C << endl;
    }

private:
    int m_A;
    int m_B;
    int m_C;
};
void test01()
{
    Person p(10, 20, 30);
    // cout << p.m_A << endl;
    // cout << p.m_B << endl;
    // cout << p.m_C << endl;
}

int main()
{
    test01();
    return 0;
}