//
// Created by 27140 on 24-9-2.
//
#include <chrono>
#include<iostream>
#include<random>
using namespace std;

int get_random_num(int min,int max)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, 100);
    int random_num = dis(gen);
    return random_num;
}


int main()
{

    //for(int day_num=1 ;day_num<=30;day_num++)
    int day_num =1;
    while (day_num<=30)
    {
        int random_num=get_random_num(1,10);
        cout<<"小明给小美表白送花的第"<<day_num<<"天"<<endl;
        if (random_num==1) {
            cout<<"小美愤怒了，表白机会彻底停止"<<endl;
            break;
        }
        else if (random_num<=5) {
            cout<<"小美不高兴了，小明继续送花"<<endl;
            day_num++;
            continue;
        }
        cout<<"今天成功了，明天再送"<<endl;
        day_num++;
    }

    return 0;
}