#include <iostream>
using namespace std;
// 作用： 通过重载递增运算符，实现自己的整型数据

class MyInt
{
    friend ostream &operator<<(ostream &cout, MyInt myint);

public:
    MyInt()
    {
        this->m_num = 10;
    }
    // 重载前置++运算符
    MyInt &operator++() // 返回引用是为了一直对一个数据进行递增操作
    {
        // 先++
        ++m_num;
        return *this; // 返回this就是返回自身，然后用*进行解引用读取自身的内容
    }
    // 重载后置++运算符
    // 后置递增返回的是局部变量，只能返回值，如果返回引用，局部变量当前函数执行完后就会被释放，会产生非法操作
    MyInt operator++(int) // 用int进行占位符，防止函数重载报错
    {
        // 先返回
        MyInt tmp = *this; // 先保存一个临时变量
        m_num++;           // 再++
        return tmp;
    }

private:
    int m_num;
};
ostream &operator<<(ostream &cout, MyInt myint)
{
    cout << myint.m_num;
    return cout;
}
void test01()
{
    MyInt myint;
    cout << ++myint << endl;
    cout << myint << endl;
}
void test02()
{
    MyInt myint;
    cout << myint++ << endl;
    cout << myint << endl;
}
int main()
{
    test01();
    test02();
    return 0;
}