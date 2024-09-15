#include <iostream>
using namespace std;
// 可以输出自定义数据类型

class Person
{
public:
    friend ostream &operator<<(ostream &cout, Person &p); // 这样就能访问私有成员了
    Person(int a, int b)
    {
        this->m_A = a;
        this->m_B = b;
    }
    // 利用成员函数重载左移运算符
    // void operator<<(Person &p)   //p.operator(cout)简化为p << cout 不是我们想要的效果
    // 通常不会用成员函数来重载左移运算符，因为无法实现cout在左边
    int m_A;
    int m_B;

private:
    int m_C = 0;
};
// 只能使用全局函数实现左移重载
ostream &operator<<(ostream &cout, Person &p) // 本质    operator<<(cout, p) 简化为 cout << p
{
    cout << "m_A:" << p.m_A << " m_B:" << p.m_B << " m_C:" << p.m_C;
    ;
    return cout;
}

void test01()
{
    Person p1(10, 10);
    cout << p1 << "hello" << endl; // 如果operator<<(cout, p1)是void 返回就不能继续链式编程  要ostream& 返回
}
int main()
{
    test01();
    return 0;
}