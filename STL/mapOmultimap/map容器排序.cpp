/*
学习目标：
map容器默认排序规则为 按照key值进行 从小到大排序，掌握如何改变排序规则

主要技术点:
利用仿函数，可以改变排序规则
*/
#include <map>
#include <iostream>
using namespace std;

class MyCompare
{
public:
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
    }
};

void test01()
{
    // 默认从小到大排序
    // 利用仿函数实现从大到小排序
    map<int, int, MyCompare> m;

    m.insert(make_pair(1, 10));
    m.insert(make_pair(2, 20));
    m.insert(make_pair(3, 30));
    m.insert(make_pair(4, 40));
    m.insert(make_pair(5, 50));

    for (map<int, int, MyCompare>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key:" << it->first << " value:" << it->second << endl;
    }
}

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

// 自定义类型数据排序
void test02()
{
    map<Person, int, PersonCompare> m;
    Person p1("刘备", 23);
    Person p2("关羽", 27);
    Person p3("张飞", 25);
    Person p4("赵云", 21);
    m.insert(pair<Person, int>(p1, 10));
    m.insert(pair<Person, int>(p2, 20));
    m.insert(pair<Person, int>(p3, 30));
    m.insert(pair<Person, int>(p4, 40));
    for (map<Person, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "姓名：" << it->first.m_Name << " 年龄：" << it->first.m_Age << " 身高：" << it->second << endl;
    }
}
int main()
{

    test01();
    test02();
    return 0;
}