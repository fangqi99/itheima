#include "Person.h"
using namespace std;
#include <algorithm>
#include <string>

Person::Person(string name, int Score)
{
    this->m_Name = name;
    this->m_Score = Score;
}
void createPerson(vector<Person> &v)
{
    string nameStr = "ABCDE";
    for (int i = 0; i < 5; i++)
    {
        string name = "选手";
        name += nameStr[i];
        int score = 0;
        Person p(name, score);
        // 将创建好的对象放入到容器中
        v.push_back(p);
    }
}
void setScore(vector<Person> &v)
{
    for (auto it = v.begin(); it != v.end(); it++)
    {
        deque<int> dScore;
        for (int i = 0; i < 10; i++) // 10次打分
        {
            int score = rand() % 41 + 60; // 60~100
            dScore.push_back(score);
        }
        // cout << "选手:" << (*it).m_Name << "的打分情况为：" << endl;
        // for (auto dit = dScore.begin(); dit != dScore.end(); dit++)
        // {
        //     cout << *dit << " ";
        // }
        // cout << endl;
        // 排序
        sort(dScore.begin(), dScore.end());
        // 去除最高分和最低分
        dScore.pop_back();
        dScore.pop_front();
        // 取平均分
        int sum = 0;
        for (auto dit = dScore.begin(); dit != dScore.end(); dit++)
        {
            sum += *dit; // 将八个评委的评分加起来
        }
        // 平均分
        int avg = sum / dScore.size();
        // 将平均分赋值给选手
        (*it).m_Score = avg;
        // it->m_Score = avg;
    }
}

void showScore(vector<Person> &v)
{
    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << (*it).m_Name << "的得分为：" << (*it).m_Score << endl;
    }
}