#pragma once
#include <iostream>
#include <string>
#include <list>
using namespace std;

// Person类
class Person
{
public:
    Person(string name, int age, int height);

public:
    string m_Name;
    int m_Age;
    int m_Height;
};
// 由于局部变量在函数结束时被销毁，因此你不应该返回它的引用。常见的解决方案是返回值，而不是引用。
list<Person> createList();
// 用指针进行返回
list<Person> *createListptr();

void showList(const list<Person> &L);

void sortList(list<Person> &L);

bool sortRule(Person &p1, Person &p2);