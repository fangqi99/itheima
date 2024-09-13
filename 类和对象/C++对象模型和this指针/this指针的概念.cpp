#include <iostream>
using namespace std;

class Person
{
public:
    Person(int age)
    {
        // this指针指向被调用的成员函数所属的对象
        this->age = age;
    }
    Person &PersonAddAge(Person &p) // 要加引用 不然返回的不是本身
    {
        this->age += p.age;
        return *this; // 返回对象本身
    }
    int age;
};
// 1解决名称冲突问题
void test01()
{
    Person p(10);
    cout << p.age << endl;
}
// 2返回对象本身用*this
void test02()
{
    Person p1(11);
    Person p2(12);
    p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);
    cout << "p2的age为：" << p2.age << endl;
}
int main()
{
    // test01();
    test02();
    cout << "1" << endl;
    return 0;
}