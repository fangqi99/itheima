/*
两种创建方式：

pair<type, type> p ( value1, value2 );
pair<type, type> p = make_pair( value1, value2 );
*/

#include <string>
#include <iostream>
#include <string>
using namespace std;

// 对组创建
void test01()
{
    pair<string, int> p(string("Tom"), 20);
    cout << "姓名： " << p.first << " 年龄： " << p.second << endl;

    pair<string, int> p2 = make_pair("Jerry", 10);
    cout << "姓名： " << p2.first << " 年龄： " << p2.second << endl;
}

int main()
{

    test01();

    return 0;
}