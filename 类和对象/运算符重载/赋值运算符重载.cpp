#include <iostream>
using namespace std;

class Person
{
public:
    Person(int age)
    {
        this->m_age = new int(age); // 用了new要自己写delete
    }
    ~Person()
    {
        if (this->m_age != NULL)
        {
            delete this->m_age;
            this->m_age = NULL;
        }
    }

    // 重载赋值运算符
    Person &operator=(Person &p) // 返回值用引用可以连等赋值
    {
        // 编译器提供的代码是浅拷贝
        // m_Age = p.m_Age;

        // 先判断是否有属性在堆区，如果有先释放，在深拷贝赋值
        if (this->m_age != NULL)
        {
            delete this->m_age;
            this->m_age = NULL;
        }
        // 深拷贝
        this->m_age = new int(*p.m_age);
        return *this;
    }
    int *m_age;
};
void test01()
{
    Person p1(18);
    Person p2(20);
    Person p3(30);
    p3 = p2 = p1; // 将p1的内容赋值给p2
    cout << *p1.m_age << endl;
    cout << *p2.m_age << endl;
    cout << *p3.m_age << endl;
}
int main()
{
    test01();
    return 0;
}