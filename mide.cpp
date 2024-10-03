// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// class Solution
// {
// public:
//     // 辅助函数，寻找两个有序数组中第 k 小的数
//     int findKthElement(const vector<int> &nums1, const vector<int> &nums2, int k)
//     {
//         int index1 = 0, index2 = 0;

//         while (true)
//         {
//             // 边界情况
//             if (index1 == nums1.size())
//             {
//                 return nums2[index2 + k - 1];
//             }
//             if (index2 == nums2.size())
//             {
//                 return nums1[index1 + k - 1];
//             }
//             if (k == 1)
//             {
//                 return min(nums1[index1], nums2[index2]);
//             }

//             // 正常情况，比较两个数组的第 k//2 小的元素
//             int new_index1 = min(index1 + k / 2 - 1, (int)nums1.size() - 1);
//             int new_index2 = min(index2 + k / 2 - 1, (int)nums2.size() - 1);
//             int pivot1 = nums1[new_index1], pivot2 = nums2[new_index2];

//             if (pivot1 <= pivot2)
//             {
//                 k -= new_index1 - index1 + 1;
//                 index1 = new_index1 + 1;
//             }
//             else
//             {
//                 k -= new_index2 - index2 + 1;
//                 index2 = new_index2 + 1;
//             }
//         }
//     }

//     double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
//     {
//         int total_length = nums1.size() + nums2.size();
//         if (total_length % 2 == 1)
//         {
//             // 总长度为奇数时，中位数为第 (m+n+1)/2 小的数
//             return findKthElement(nums1, nums2, (total_length + 1) / 2);
//         }
//         else
//         {
//             // 总长度为偶数时，中位数为第 (m+n)/2 和 (m+n)/2 + 1 小的数的平均值
//             return (findKthElement(nums1, nums2, total_length / 2) +
//                     findKthElement(nums1, nums2, total_length / 2 + 1)) /
//                    2.0;
//         }
//     }
// };

// int main()
// {
//     Solution solution;

//     vector<int> nums1 = {1, 3};
//     vector<int> nums2 = {2};
//     cout << "中位数: " << solution.findMedianSortedArrays(nums1, nums2) << endl; // 输出: 2.0

//     vector<int> nums1_2 = {1, 2};
//     vector<int> nums2_2 = {3, 4};
//     cout << "中位数: " << solution.findMedianSortedArrays(nums1_2, nums2_2) << endl; // 输出: 2.5

//     return 0;
// }
#include <iostream>
using namespace std;

// 比较两个数的大小
int min(int a, int b)
{
    return (a < b) ? a : b;
}

// 找到两个数组合并后的第 k 小的数
double findKth(int nums1[], int m, int nums2[], int n, int k)
{
    // 如果 nums1 为空，直接返回 nums2 的第 k 个元素
    if (m == 0)
        return nums2[k - 1];
    // 如果 nums2 为空，直接返回 nums1 的第 k 个元素
    if (n == 0)
        return nums1[k - 1];

    // 计算 nums1 和 nums2 的中间位置
    int mid1 = m / 2;
    int mid2 = n / 2;

    // 如果 nums1[mid1] <= nums2[mid2]
    if (nums1[mid1] <= nums2[mid2])
    {
        // 如果 k 小于等于 mid1 + mid2 + 1，在 nums1 的前半部分和 nums2 中找第 k 小的数
        if (k <= mid1 + mid2 + 1)
        {
            return findKth(nums1, mid1, nums2, n, k);
        }
        else
        {
            // 否则在 nums1 的后半部分和 nums2 中找第 k - mid1 - 1 小的数
            return findKth(nums1 + mid1 + 1, m - mid1 - 1, nums2, n, k - mid1 - 1);
        }
    }
    else
    {
        // 如果 nums2[mid2] < nums1[mid1]
        // 如果 k 小于等于 mid1 + mid2 + 1，在 nums2 的前半部分和 nums1 中找第 k 小的数
        if (k <= mid1 + mid2 + 1)
        {
            return findKth(nums1, m, nums2, mid2, k);
        }
        else
        {
            // 否则在 nums2 的后半部分和 nums1 中找第 k - mid2 - 1 小的数
            return findKth(nums1, m, nums2 + mid2 + 1, n - mid2 - 1, k - mid2 - 1);
        }
    }
}

// 计算两个已排序数组合并后的中位数
double findMedianSortedArrays(int nums1[], int m, int nums2[], int n)
{
    int totalLength = m + n;
    // 如果总长度为奇数
    if (totalLength % 2 == 1)
    {
        return findKth(nums1, m, nums2, n, totalLength / 2 + 1);
    }
    else
    {
        // 如果总长度为偶数
        return (findKth(nums1, m, nums2, n, totalLength / 2) + findKth(nums1, m, nums2, n, totalLength / 2 + 1)) / 2.0;
    }
}

int main()
{
    int nums1[] = {1, 2};
    int m = sizeof(nums1) / sizeof(nums1[0]);
    int nums2[] = {3, 4};
    int n = sizeof(nums2) / sizeof(nums2[0]);

    double median = findMedianSortedArrays(nums1, m, nums2, n);
    cout << "中位数是: " << median << endl;

    return 0;
}