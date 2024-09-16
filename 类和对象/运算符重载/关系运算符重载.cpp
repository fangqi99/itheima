#include <iostream>
using namespace std;

class Person
{
public:
    Person(string name, int age) // 利用构造函数进行初始化
    {
        this->m_name = name;
        this->m_age = age;
    }
    // 重载==
    bool operator==(Person &p)
    {
        if (this->m_age == p.m_age && this->m_name == p.m_name)
        {
            return true;
        }
        return false;
    }
    // 重载！=
    bool operator!=(Person &p)
    {
        if (this->m_age == p.m_age && this->m_name == p.m_name)
        {
            return false;
        }
        return true;
    }
    string m_name;
    int m_age;
};
void test01()
{
    Person p1("Tom", 20);
    Person p2("Jerry", 30);
    if (p1 == p2)
    {
        cout << "p1和p2是同一个人" << endl;
    }
    else
    {
        cout << "p1和p2不是同一个人" << endl;
    }
    if (p1 != p2)
    {
        cout << "p1和p2不是同一个人" << endl;
    }
    else
    {
        cout << "p1和p2是同一个人" << endl;
    }
}
int main()
{
    test01();
    return 0;
}