#include <iostream>
using namespace std;

class Base
{
public:
    int m_A;
    static int m_E; // 静态变量不会被继承

protected:
    int m_B;

private:
    int m_C; // 私有成员只是被隐藏了，但是还是会继承下去
};

// 公共继承
class Son : public Base
{
public:
    int m_D;
};

void test01()
{
    // 父类中所有非静态成员属性都会被子类继承下去
    // 父类中私有成员属性是被编译器给隐藏了，访问不到，但确实被继承了
    cout << "sizeof Son = " << sizeof(Son) << endl; // 结果是16 说明有四个整型变量，全部继承下来了
}

int main()
{
    test01();
    return 0;
}