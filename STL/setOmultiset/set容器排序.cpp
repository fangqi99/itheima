/*
学习目标：set容器默认排序规则为从小到大，掌握如何改变排序规则
主要技术点：利用仿函数(类似重载小括号)，可以改变排序规则
*/

#include <iostream>
#include <set>
#include <string>
using namespace std;

class Person
{
public:
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

    string m_Name;
    int m_Age;
};

class PersonCompare
{
public:
    bool operator()(const Person &p1, const Person &p2)
    {
        return p1.m_Age > p2.m_Age; // 按年龄降序
    }
};

class MyCompare
{
public:
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
    }
};
// set存放内置数据类型
void test01()
{
    set<int> s1;
    s1.insert(10);
    s1.insert(30);
    s1.insert(20);
    s1.insert(40);
    s1.insert(50);
    for (set<int>::iterator it = s1.begin(); it != s1.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    // 指定排序规则为从大到小
    set<int, MyCompare> s2;
    s2.insert(10);
    s2.insert(30);
    s2.insert(20);
    s2.insert(40);
    s2.insert(50);
    for (auto it = s2.begin(); it != s2.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
// set存放自定义数据类型
void test02()
{
    set<Person, PersonCompare> s;
    Person p1("刘备", 23);
    Person p2("关羽", 27);
    Person p3("张飞", 25);
    Person p4("赵云", 21);
    s.insert(p1);
    s.insert(p2);
    s.insert(p3);
    s.insert(p4);
    for (set<Person>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << "姓名：" << (*it).m_Name << " 年龄：" << (*it).m_Age << endl;
    }
}
int main()
{
    // test01();
    test02();
    return 0;
}