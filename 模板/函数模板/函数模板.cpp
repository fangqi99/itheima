#include <iostream>
using namespace std;
// 函数模板作用：
// 建立一个通用函数，其函数返回值类型和形参类型可以不具体制定，用一个虚拟的类型来代表。
/*
总结：
函数模板利用关键字 template
使用函数模板有两种方式：自动类型推导、显示指定类型
模板的目的是为了提高复用性，将类型参数化
*/
// 交换整型函数
void swapInt(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
// 交换浮点型函数
void swapDouble(double &a, double &b)
{
    double temp = a;
    a = b;
    b = temp;
}
// 利用模板提供通用的交换函数
template <typename T>
void mySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}
void test01()
{
    int a = 10;
    int b = 20;
    // 1、自动类型推导
    mySwap(a, b);
    cout << "a = " << a << " b = " << b << endl;
    // 2、显示指定类型
    mySwap<int>(a, b);
    cout << "a = " << a << " b = " << b << endl;
}
int main()
{
    test01();
    return 0;
}