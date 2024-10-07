// 函数原型：reserve(int len);//容器预留len个元素长度，预留位置不初始化，元素不可访问。

#include <vector>
#include <iostream>
using namespace std;
void test01()
{
    vector<int> v;

    // 预留空间后num是1
    v.reserve(100000);

    int num = 0; // 统计开辟次数
    int *p = NULL;
    for (int i = 0; i < 100000; i++)
    {
        v.push_back(i);
        if (p != &v[0])
        {
            p = &v[0];
            num++;
        }
    }

    cout << "num:" << num << endl;
}

int main()
{

    test01();

    return 0;
}
// 总结：如果数据量较大，可以一开始利用reserve预留空间