#include <iostream>
using namespace std;

#include <string>
/*
类模板与函数模板区别主要有两点：

类模板没有自动类型推导的使用方式
类模板在模板参数列表中可以有默认参数*/

// 类模板
template <class NameType, class AgeType = int> // 默认是整型
class Person
{
public:
    Person(NameType name, AgeType age)
    {
        this->mName = name;
        this->mAge = age;
    }
    void showPerson()
    {
        cout << "name: " << this->mName << " age: " << this->mAge << endl;
    }

public:
    NameType mName;
    AgeType mAge;
};

// 1、类模板没有自动类型推导的使用方式
void test01()
{
    // Person p("孙悟空", 1000); // 错误 类模板使用时候，不可以用自动类型推导
    Person<string, int> p("孙悟空", 1000); // 必须使用显示指定类型的方式，使用类模板
    p.showPerson();
}

// 2、类模板在模板参数列表中可以有默认参数
void test02()
{
    Person<string> p("猪八戒", 999); // 类模板中的模板参数列表 可以指定默认参数
    p.showPerson();
}

int main()
{

    test01();

    test02();

    system("pause");

    return 0;
}