#include <iostream>
using namespace std;
// 函数重载需要函数都在同一个作用域下
void func()
{
    cout << "func 的调用！" << endl;
}
void func(int a)
{
    cout << "func (int a) 的调用！" << endl;
}
void func(double a)
{
    cout << "func (double a)的调用！" << endl;
}
void func(int a, double b)
{
    cout << "func (int a ,double b) 的调用！" << endl;
}
void func(double a, int b)
{
    cout << "func (double a ,int b)的调用！" << endl;
}

// 函数返回值不可以作为函数重载条件
// int func(double a, int b)
//{
//	cout << "func (double a ,int b)的调用！" << endl;
// }

// 函数重载注意事项
// 1、引用作为重载条件
void func1(int &a)
{
    cout << "func (int &a) 调用 " << endl;
}

void func1(const int &a)
{
    cout << "func (const int &a) 调用 " << endl;
}

// 2、函数重载碰到函数默认参数

void func2(int a, int b = 10)
{
    cout << "func2(int a, int b = 10) 调用" << endl;
}

void func2(int a)
{
    cout << "func2(int a) 调用" << endl;
}

int main()
{

    func();
    func(10);
    func(3.14);
    func(10, 3.14);
    func(3.14, 10);
    // int a = 10;
    // func1(a);
    func1(10);
    // func2(10); // 会出现歧义，编译器无法确定调用哪个函数
    func2(10, 20);
    return 0;
}