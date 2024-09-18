#include <iostream>
#include <fstream>
using namespace std;
/*
程序运行时产生的数据都属于临时数据，程序一旦运行结束都会被释放
通过文件可以将数据持久化
C++中对文件操作需要包含头文件 < fstream >

文件类型分为两种：
文本文件 - 文件以文本的ASCII码形式存储在计算机中
二进制文件 - 文件以文本的二进制形式存储在计算机中，用户一般不能直接读懂它们

操作文件的三大类:
ofstream：写操作
ifstream： 读操作
fstream ： 读写操作
*/
void test01()
{
    ofstream ofs;
    ofs.open("test.txt", ios::out); // ios::out 表示写操作 ios::in 表示读操作
    ofs << "姓名： 张三" << endl;
    ofs << "年龄： 18" << endl;
    ofs << "性别： 男" << endl;
    ofs.close();
}
int main()
{
    test01();
    return 0;
}