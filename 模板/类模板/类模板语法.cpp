#include <iostream>
using namespace std;

#include <string>

// 类模板
// template <class NameType, class AgeType>
template <typename NameType, typename AgeType> // 这两个都可以
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

void test01()
{
    // 指定NameType 为string类型，AgeType 为 int类型
    Person<string, int> P1("孙悟空", 999);
    P1.showPerson();
}

int main()
{

    test01();

    return 0;
}