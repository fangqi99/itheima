/*
函数原型：

copy(iterator beg, iterator end, iterator dest);
按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
beg 开始迭代器
end 结束迭代器
dest 目标起始迭代器
*/
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class myPrint
{
public:
    void operator()(int val)
    {
        cout << val << " ";
    }
};

void test01()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i + 1);
    }
    vector<int> v2;
    v2.resize(v1.size());
    copy(v1.begin(), v1.end(), v2.begin());

    for_each(v2.begin(), v2.end(), myPrint());
    cout << endl;
}

int main()
{

    test01();
    return 0;
}