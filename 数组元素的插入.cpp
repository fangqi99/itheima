#include <iostream>
#include <string>
using namespace std;

int main()
{

    // 移除多个元素
    int a;
    int *pArr = new int[10]{3, 5, 1, 11, 99, 66, 22, 2, 8, 6};
    cin >> a;
    int *pNewArr = new int[12];

    int offset = 0;
    // for循环遍历老的数组，将需要的元素一个个放入新数组中
    for (int i = 0; i < 12; i++)
    {
        if (i == 1)
        {
            pNewArr[i] = 12;
            offset++;
            continue;
        }
        else if (i == 3)
        {
            pNewArr[i] = 66;
            offset++;
            continue;
        }
        pNewArr[i] = pArr[i - offset]; // 是对新数组进行循环，要注意，不要超出了
    }
    // 回收老数组空间
    delete[] pArr;
    // 可选 将老数组的指针对象指向新数组空间
    // pArr = pNewArr;
    // 遍历新数组
    for (int i = 0; i < 12; i++)
    {
        cout << pNewArr[i] << " ";
    }

    return 0;
}