//
// Created by 27140 on 24-9-4.
//
#include <iostream>
#include <random>
using namespace std;

int get_random_num(int min,int max)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, 10);
    int random_num = dis(gen);
    return random_num;
}

int main() {
    int arr[10];
    int max = INT_MIN; // 初始最大值设为整数最小值
    int min = INT_MAX; // 初始最小值设为整数最大值
    for(int i = 0; i < 10; i++) {
        arr[i]=get_random_num(1,10);
    }
    for (int element : arr) {
            cout << element << " ";
    }
    cout<<endl;
    for(int element : arr) {
        //判断arr数组中哪个元素是最大，哪个元素最小
        if (element<min) {
            min = element;
        }
        else if (element>max) {
            max = element;
        }
    }
    cout<<"最大值为："<<max<<endl;
    cout<<"最小值为："<<min<<endl;


    return 0;
}