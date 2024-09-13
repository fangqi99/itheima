#include <iostream>
using namespace std;
// int &test01()
// {
//     int a = 10; // 局部变量 在栈区，用完就被删除了，返回不了
//     return a;
// }
int &test02()
{
    static int a = 20; // 加上static关键字，静态变量就在全局区了在函数执行完，a的值还在，不会被删除
    return a;
}

int main()
{
    int &ref = test02();
    cout << ref << endl;
    cout << ref << endl;
    test02() = 1000; // 函数返回的是引用，可以修改引用指向的值
    cout << ref << endl;
    cout << ref << endl;
    return 0;
}