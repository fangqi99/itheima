/*
功能描述：

查找：查找指定字符串是否存在
替换：在指定的位置替换字符串
函数原型：

int find(const string& str, int pos = 0) const; //查找str第一次出现位置,从pos开始查找
int find(const char* s, int pos = 0) const; //查找s第一次出现位置,从pos开始查找
int find(const char* s, int pos, int n) const; //从pos位置查找s的前n个字符第一次位置
int find(const char c, int pos = 0) const; //查找字符c第一次出现位置
int rfind(const string& str, int pos = npos) const; //查找str最后一次位置,从pos开始查找
int rfind(const char* s, int pos = npos) const; //查找s最后一次出现位置,从pos开始查找
int rfind(const char* s, int pos, int n) const; //从pos查找s的前n个字符最后一次位置
int rfind(const char c, int pos = 0) const; //查找字符c最后一次出现位置
string& replace(int pos, int n, const string& str); //替换从pos开始n个字符为字符串str
string& replace(int pos, int n,const char* s); //替换从pos开始的n个字符为字符串s
*/

#include <iostream>
#include <string>
using namespace std;

// 查找和替换
void test01()
{
    // 查找
    string str1 = "abcdefgde";

    int pos = str1.find("de"); // 没有返回-1

    if (pos == -1)
    {
        cout << "未找到" << endl;
    }
    else
    {
        cout << "de的pos = " << pos << endl;
    }

    int pos1 = str1.rfind("de"); // rfind从后往前找

    cout << "pos1 = " << pos1 << endl;
}

void test02()
{
    // 替换
    string str1 = "abcdefgde";
    str1.replace(1, 3, "1111"); /// 替换从1开始的3个字符替换为字符串1111
    cout << "str1 = " << str1 << endl;
}

int main()
{

    test01();
    test02();

    return 0;
}