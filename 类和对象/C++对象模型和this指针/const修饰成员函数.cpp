#include <iostream>
using namespace std;

class Person
{
public:
    Person()
    {
        m_A = 0;
        m_B = 0;
    }
    // this指针的本质是一个常量指针，指针的指向是不可以修改的
    // 常函数
    void showPerson() const // 在成员函数后面加const，修饰的是this指针，指针指向的值不可以修改
    {
        // this->m_A = 20; //
        this->m_B = 20;
    }
    void func()
    {
    }
    int m_A;
    mutable int m_B; // 这样就可以修改了
};

void test01()
{
    Person p;
    p.showPerson();
}
// 常对象
void test02()
{
    const Person p; // 在对象前加const 变为常对象
    // p.m_A = 100;
    p.m_B = 100; // b可以修改
    // p.func();//常对象只能调用常函数
    p.showPerson();
}

int main()
{
    test01();
    test02();
    return 0;
}