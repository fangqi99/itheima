#include "Person.h"
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

int main()
{
    // 随机数种子
    srand((unsigned int)time(NULL));
    // 存放选手的容器
    vector<Person> v;
    createPerson(v);
    // 测试
    // for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    // {
    //     cout << "姓名：" << it->m_Name << " 分数：" << it->m_Score << endl;
    // }
    // 2. 打分
    setScore(v);
    showScore(v);
    return 0;
}