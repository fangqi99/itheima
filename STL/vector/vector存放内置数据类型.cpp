#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void myprint(int val)
{
    cout << val << " ";
}

void test01()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    // 使用迭代器访问容器中的元素
    // v.begin()返回迭代器，这个迭代器指向容器中第一个数据
    vector<int>::iterator itBegin = v.begin();
    // v.end()返回迭代器，这个迭代器指向容器中最后一个数据的下一个位置
    vector<int>::iterator itEnd = v.end();
    // vector<int>::iterator 拿到vector<int>这种容器的迭代器类型

    // 遍历vector--方法1
    while (itBegin != itEnd)
    {
        cout << *itBegin << " ";
        itBegin++;
    }
    cout << endl;
    // 遍历vector--方法2
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    // 遍历vector--方法3
    // 利用迭代器的方式，使用STL算法
    for_each(v.begin(), v.end(), myprint);
}

int main()
{
    test01();
    return 0;
}
