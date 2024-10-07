#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 容器嵌套容器
void test01()
{
    vector<vector<int>> v;
    // 创建小容器
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    vector<int> v4;
    for (int i = 0; i < 4; i++)
    {
        v1.push_back(i + 1);
        v2.push_back(i + 2);
        v3.push_back(i + 3);
        v4.push_back(i + 4);
    }
    // 添加小容器到大容器
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);
    // 遍历
    for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
    {
        for (vector<int>::iterator it2 = (*it).begin(); it2 != (*it).end(); it2++)
        {
            cout << *it2 << " ";
        }
        cout << endl;
    }
    // 使用 for_each 和 lambda 遍历二维 vector
    // for_each(v.begin(), v.end(), [](const vector<int> &vec)
    //          {
    //              std::for_each(vec.begin(), vec.end(), [](int val)
    //                            {
    //                                cout << val << " "; // 输出每个元素
    //                            });
    //              cout << endl; // 换行
    //          });
}
int main()
{
    test01();
    return 0;
}