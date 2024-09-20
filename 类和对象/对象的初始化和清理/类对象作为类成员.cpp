#include <iostream>
using namespace std;

class Phone
{
public:
    Phone(string name) : m_phoneName(name)
    {
        cout << "Phone构造函数" << endl;
    }
    ~Phone()
    {
        cout << "Phone析构函数" << endl;
    }
    string m_phoneName;
};

class Person
{
public:
    Person(string name, string phonename) : m_name(name), m_phone(phonename)
    {
        cout << "Person构造函数" << endl;
    }
    void playgame()
    {
        cout << m_name << "在用" << m_phone.m_phoneName << "手机玩游戏" << endl;
    }
    ~Person()
    {
        cout << "Person析构函数" << endl;
    }
    string m_name;
    Phone m_phone;
};

int main()
{
    Person p("张三", "苹果");
    p.playgame();
    return 0;
}