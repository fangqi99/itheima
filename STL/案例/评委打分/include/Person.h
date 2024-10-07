#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <deque>
using namespace std;

// 选手类
class Person
{
public:
    Person(string name, int Score);

public:
    string m_Name;
    int m_Score;
};

void createPerson(vector<Person> &v);

void setScore(vector<Person> &v);
void showScore(vector<Person> &v);