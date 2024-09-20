#include <iostream>
using namespace std;

int main()
{
    int num1 = 10;
    int num2 = 20;
    const int *p1 = &num1; // 常量指针

    //*p = 20;   // 指针指向的值不可以修改
    p1 = &num2; // 指针指向的地址可以修改、即修改指针指向

    int *const p2 = &num1; // 指针常量
    *p2 = 20;
    // p2 = &num2;
    const int *const p3 = &num1;

    return 0;
}