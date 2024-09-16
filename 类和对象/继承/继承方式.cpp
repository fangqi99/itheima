#include <iostream>
using namespace std;

class Base1
{
public:
    int m_A;

protected:
    int m_B;

private:
    int m_C;
};
// 公共继承
class Son1 : public Base1
{
public:
    void func()
    {
        m_A = 10; // 可访问 public权限
        m_B = 11; // 可访问 protected权限
        // m_C=12; //不可访问
    }
};

void myClass()
{
    Son1 s1;
    s1.m_A; // 其他类只能访问到公共权限
    // s1.m_B; // 到了son1 中m_B是protected权限 类外访问不到
}

// 保护继承
class Base2
{
public:
    int m_A;

protected:
    int m_B;

private:
    int m_C;
};
class Son2 : protected Base2
{
public:
    void func()
    {
        m_A = 100; // 可访问 protected权限
        m_B = 110; // 可访问 protected权限
        // m_C=120; //不可访问
    }
};
void myClass2()
{
    Son2 s1;
    // s1.m_A; //在son2 中m_A是protected权限 类外访问不到
    // s1.m_B;//同样也访问不到
}

// 私有继承
class Base3
{
public:
    int m_A;

protected:
    int m_B;

private:
    int m_C;
};
class Son3 : private Base3
{
public:
    void func()
    {
        m_A; // 可访问 在子类变为private权限
        m_B; // 可访问 在子类变为private权限
        // m_C; //不可访问
    }
};
class GrandSon3 : public Son3
{
public:
    void func()
    {
        // Son3是私有继承，所以继承Son3的属性在GrandSon3中都无法访问到
        // m_A;
        // m_B;
        // m_C;
    }
};
void myClass3()
{
    Son3 s1;
    // s1.m_A; // 在son3中变为son3的private权限，类外访问不到
}
int main()
{
    myClass();
    myClass2();
    return 0;
}