#include <iostream>
using namespace std;
// 如果属性有在堆区开辟的，一定要自己提供拷贝构造函数，防止浅拷贝带来的问题
class Person
{
public:
    Person()
    {
        cout << "Person默认构造函数调用成功" << endl;
    }
    Person(int a, int h)
    {
        cout << "Person有参构造函数调用成功" << endl;
        m_A = a;
        m_H = new int(h); // new一个堆区的int型数据
    }
    // 编译器提供的都是浅拷贝，不好使。自己写拷贝构造函数就是深拷贝
    Person(const Person &p)
    {
        cout << "Person拷贝构造函数调用成功" << endl;
        m_A = p.m_A;
        // m_H = p.m_H;           // 这是编译器默认实现的，不好用是浅拷贝
        m_H = new int(*p.m_H); // 深拷贝应该这样写 *p.m_H表示内存里的内容
    }
    ~Person()
    {
        // 因为开辟的堆区，现在析构代码有用了，要进行堆区释放
        cout << "Person析构函数调用成功" << endl;
        if (m_H != NULL)
        {
            delete m_H;
            m_H = NULL; // 置空，防止野指针出现
        }
    }
    int m_A;
    int *m_H;
};

void test01()
{
    Person p1(10, 190);
    Person p2(p1); // 没有拷贝构造函数，编译器会进行浅拷贝，导致p2.m_A = 10 浅拷贝 ---会使堆区内存重复释放
    cout << "p1.m_A = " << p1.m_A << "p1.m_H= " << *p1.m_H << endl;
    cout << "p2.m_A = " << p2.m_A << "p2.m_H= " << *p2.m_H << endl;
}

int main()
{
    test01();
    return 0;
}
