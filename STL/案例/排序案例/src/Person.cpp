#include "D:\clionproject\itheima\STL\案例\排序案例\include\Person.h" //有中文-使用绝对路径避免报错
// #include <list>

Person::Person(string name, int age, int height)
{
    this->m_Name = name;
    this->m_Age = age;
    this->m_Height = height;
}
list<Person> createList()
{
    list<Person> L;
    Person p1("刘备", 35, 175);
    Person p2("曹操", 45, 180);
    Person p3("孙权", 40, 170);
    Person p4("赵云", 25, 190);
    Person p5("张飞", 35, 160);
    Person p6("关羽", 35, 200);

    L.push_back(p1);
    L.push_back(p2);
    L.push_back(p3);
    L.push_back(p4);
    L.push_back(p5);
    L.push_back(p6);
    return L;
}
list<Person> *createListptr()
{
    list<Person> *L = new list<Person>;
    Person p1("刘备", 35, 175);
    Person p2("曹操", 45, 180);
    Person p3("孙权", 40, 170);
    Person p4("赵云", 25, 190);
    Person p5("张飞", 35, 160);
    Person p6("关羽", 35, 200);
    // L是指针用->或（*L）
    (*L).push_back(p1);
    L->push_back(p2);
    L->push_back(p3);
    L->push_back(p4);
    L->push_back(p5);
    L->push_back(p6);
    return L;
}

void showList(const list<Person> &L)
{
    for (auto it = L.begin(); it != L.end(); it++)
    {
        cout << "姓名：" << it->m_Name << " 年龄：" << it->m_Age << " 身高：" << it->m_Height << endl;
    }
}

bool sortRule(Person &p1, Person &p2)
{
    // 按照年龄升序，并且年龄相同，按身高降序排列
    if (p1.m_Age == p2.m_Age)
    {
        return p1.m_Height > p2.m_Height;
    }
    else
    {
        return p1.m_Age < p2.m_Age; // 这样就会返回真
    }
}
void sortList(list<Person> &L)
{
    L.sort(sortRule);
    // 显示排序后的内容
    // for (list<Person>::iterator it = L.begin(); it != L.end(); it++)
    // {
    //     cout << "姓名：" << it->m_Name << " 年龄：" << it->m_Age << " 身高：" << it->m_Height << endl;
    // }
}
