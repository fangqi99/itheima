#include <iostream>
#include <vector>
#include <string>
using namespace std;
// 自定义数据类型
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

void test01()
{
    // 创建vector对象
    vector<Person> v;

    // 创建数据
    Person p1("A", 10);
    Person p2("B", 20);
    Person p3("C", 30);
    Person p4("D", 40);
    Person p5("E", 50);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);
    // 遍历
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "name:" << (*it).m_Name << " " << "age:" << (*it).m_Age << endl;
        cout << "name:" << it->m_Name << " " << "age:" << it->m_Age << endl;
    }
}
// 放对象指针
void test02()
{
    vector<Person *> pv;
    // 创建数据
    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 30);
    Person p4("ddd", 40);
    Person p5("eee", 50);

    pv.push_back(&p1); // 将地址压入
    pv.push_back(&p2);
    pv.push_back(&p3);
    pv.push_back(&p4);
    pv.push_back(&p5);

    for (vector<Person *>::iterator it = pv.begin(); it != pv.end(); it++)
    {
        cout << "name:" << (*it)->m_Name << " " << "age:" << (*it)->m_Age << endl; // （*it）完后是地址在通过->去地址里的值
        cout << "name:" << (**it).m_Name << " " << "age:" << (**it).m_Age << endl;
    }
}
int main()
{
    test01();
    cout << "---------------" << endl;
    test02();
    return 0;
}