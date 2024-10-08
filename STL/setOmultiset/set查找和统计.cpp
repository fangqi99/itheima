/*
函数原型：

find(key); //查找key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end();
count(key); //统计key的元素个数
*/
#include <set>
#include <iostream>
using namespace std;

// 查找和统计
void test01()
{
    set<int> s1;
    // 插入
    s1.insert(10);
    s1.insert(30);
    s1.insert(20);
    s1.insert(40);

    // 查找
    // s1.find(30)返回该键的元素的迭代器；若不存在，返回set.end();
    set<int>::iterator pos = s1.find(30); // 查找元素30所在的迭代器

    if (pos != s1.end())
    {
        cout << "找到了元素 ： " << *pos << endl;
    }
    else
    {
        cout << "未找到元素" << endl;
    }

    // 统计
    int num = s1.count(30);
    cout << "num = " << num << endl;
}

int main()
{

    test01();
    return 0;
}