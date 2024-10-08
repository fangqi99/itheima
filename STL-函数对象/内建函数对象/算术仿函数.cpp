/*
STL内建了一些函数对象
分类:
算术仿函数

关系仿函数

逻辑仿函数

用法：
这些仿函数所产生的对象，用法和一般函数完全相同
使用内建函数对象，需要引入头文件 #include<functional>

仿函数原型：
template<class T> T plus<T> //加法仿函数
template<class T> T minus<T> //减法仿函数
template<class T> T multiplies<T> //乘法仿函数
template<class T> T divides<T> //除法仿函数
template<class T> T modulus<T> //取模仿函数
template<class T> T negate<T> //取反仿函数
*/

#include <iostream>
#include <functional>
using namespace std;

// negate 函数对象，对元素取反
void test01()
{
    negate<int> n;
    cout << n(10) << endl; // -10
}
void test02()
{
    plus<int> p;
    cout << p(10, 20) << endl;
}

int main()
{
    test01();
    return 0;
}
// 总结：使用内建函数对象时，需要引入头文件 #include <functional>