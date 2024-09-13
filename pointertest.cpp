#include <iostream>
#include <string>
using namespace std;

int main()
{

    // 移除多个元素
    int *pArr = new int[10]{3, 5, 1, 11, 99, 66, 22, 2, 8, 6};
    int *pNewArr = new int[8];
    int offset = 0;
    // for循环遍历老的数组，将需要的元素一个个放入新数组中
    for (int i = 0; i < 10; i++)
    {
        if (i == 0 || i == 5)
        {
            offset++;
            continue;
        }
        pNewArr[i - offset] = pArr[i];
    }
    // 回收老数组空间
    delete[] pArr;
    // 可选 将老数组的指针对象指向新数组空间
    // pArr = pNewArr;
    // 遍历新数组
    for (int i = 0; i < 8; i++)
    {
        cout << pNewArr[i] << " ";
    }

    return 0;
}