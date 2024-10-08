#pragma once
#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

class Empolyee
{
public:
    Empolyee(string name, int salary);

    string m_Name;
    int m_Salary;
};

void createEmployee(vector<Empolyee> &v);
void printEmployee(vector<Empolyee> &v);
void setGroup(vector<Empolyee> &v, multimap<int, Empolyee> &m);
void showEmpByGroup(multimap<int, Empolyee> &m);
void MyShowEmpByGroup(multimap<int, Empolyee> &m);
