#include <iostream>
using namespace std;
// 也叫仿函数

class MyPrint
{
public:
    void operator()(string text)
    {
        cout << text << endl;
    }
};
// 仿函数非常灵活没有固定写法
class Myadd
{
public:
    int operator()(int v1, int v2)
    {
        return v1 + v2;
    }
};
void test01()
{
    // 重载的（）操作符 也称为仿函数
    MyPrint myFunc;
    myFunc("hello world");
}
void test02()
{
    Myadd myAdd;
    int result = myAdd(10, 20);
    cout << result << endl;
    // 匿名对象调用
    cout << "MyAdd()(100,100) = " << Myadd()(100, 100) << endl;
}
int main()
{
    test01();
    test02();
    return 0;
}