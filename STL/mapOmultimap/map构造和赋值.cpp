/*
简介：
map中所有元素都是pair
pair中第一个元素为key（键值），起到索引作用，第二个元素为value（实值）
所有元素都会根据元素的键值自动排序

本质：
map/multimap属于关联式容器，底层结构是用二叉树实现。

优点：
可以根据key值快速找到value值

map和multimap区别：
map不允许容器中有重复key值元素
multimap允许容器中有重复key值元素


函数原型：
构造：
map<T1, T2> mp; //map默认构造函数:
map(const map &mp); //拷贝构造函数

赋值：
map& operator=(const map &mp); //重载等号操作符
*/

#include <map>
#include <iostream>
using namespace std;
void printMap(map<int, int> &m)
{
    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key = " << it->first << " value = " << it->second << endl;
    }
    cout << endl;
}

void test01()
{
    map<int, int> m; // 默认构造
    m.insert(pair<int, int>(1, 10));
    m.insert(pair<int, int>(3, 30));
    m.insert(pair<int, int>(2, 20));
    printMap(m);

    map<int, int> m2(m); // 拷贝构造
    printMap(m2);

    map<int, int> m3;
    m3 = m2; // 赋值
    printMap(m3);
}

int main()
{

    test01();
    return 0;
}
// 总结：map中所有元素都是成对出现，插入数据时候要使用对组