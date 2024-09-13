#include <iostream>
using namespace std;

// 选择排序（Selection Sort）

int main()
{
    // int min;
    // int min_index;
    // // 对数组进行从小到大排序
    // int *pArr = new int[10]{3, 5, 1, 11, 99, 66, 22, 2, 8, 6};
    // int temp;
    // for (int i = 0; i < 9; i++)
    // {
    //     for (int j = i; j < 10; j++)
    //     {
    //         if (i == j)
    //         {
    //             min = pArr[i];
    //             min_index = i;
    //         }
    //         else if (pArr[j] < min)
    //         {
    //             min = pArr[j];
    //             min_index = j;
    //         }
    //     }
    //     temp = pArr[i];
    //     pArr[i] = min;
    //     pArr[min_index] = temp;
    // }
    // for (int i = 0; i < 10; i++)
    // {
    //     cout << pArr[i] << " ";
    // }
    // delete[] pArr;
    int *pArr = new int[10]{3, 5, 1, 11, 99, 66, 22, 2, 8, 6};
    // 从大到小排序
    int max;
    int max_index;
    for (int i = 0; i < 9; i++)
    {
        for (int j = i; j < 10; j++)
        {
            if (i == j)
            {
                max = pArr[i];
                max_index = i;
            }
            if (pArr[j] > max)
            {
                max = pArr[j];
                max_index = j;
            }
        }
        int temp = pArr[i];
        pArr[i] = max;
        pArr[max_index] = temp;
    }
    for (int i = 0; i < 10; i++)
    {
        cout << pArr[i] << ",";
    }
    delete[] pArr;
    return 0;
}