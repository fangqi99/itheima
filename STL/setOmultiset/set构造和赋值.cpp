/*
简介：
所有元素都会在插入时自动被排序

本质：
set/multiset属于关联式容器，底层结构是用二叉树实现。

set和multiset区别：
set不允许容器中有重复的元素
multiset允许容器中有重复的元素

构造：
set<T> st; //默认构造函数：
set(const set &st); //拷贝构造函数

赋值：
set& operator=(const set &st); //重载等号操作符
*/

#include <set>
#include <iostream>
using namespace std;
void printSet(set<int> &s)
{
    for (set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
void printMSet(multiset<int> &ms)
{
    for (set<int>::iterator it = ms.begin(); it != ms.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

// 构造和赋值
void test01()
{
    set<int> s1;
    // 插入数据只有insert一种方式
    s1.insert(10);
    s1.insert(10);
    s1.insert(30);
    s1.insert(30);
    s1.insert(40);
    s1.insert(20);
    printSet(s1);

    // 拷贝构造
    set<int> s2(s1);
    printSet(s2);

    // 赋值
    set<int> s3;
    s3 = s2;
    printSet(s3);

    multiset<int> ms1;
    ms1.insert(10);
    ms1.insert(10);
    ms1.insert(30);
    ms1.insert(30);
    ms1.insert(40);
    ms1.insert(20);
    printMSet(ms1);
}

int main()
{

    test01();
    return 0;
}