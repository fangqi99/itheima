/*
函数原型：
bool binary_search(iterator beg, iterator end, value);
查找指定的元素，查到 返回true 否则false
注意: 在无序序列中不可用
beg 开始迭代器
end 结束迭代器
value 查找的元素
*/

#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

void test01()
{
    vector<int> v;

    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    // 二分查找
    // 二分查找，要求容器中元素有序
    // 如果是无序序列，则结果未知
    bool ret = binary_search(v.begin(), v.end(), 2);
    if (ret)
    {
        cout << "找到了" << endl;
    }
    else
    {
        cout << "未找到" << endl;
    }
}

int main()
{

    test01();
    return 0;
}
// 总结：**二分查找法查找效率很高，值得注意的是查找的容器中元素必须的有序序列