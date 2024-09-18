#include <iostream>
#include <fstream>
using namespace std;

void test01()
{
    ifstream ifs;
    ifs.open("test.txt", ios::in);
    if (!ifs.is_open())
    {
        cout << "文件打开失败！" << endl;
        return;
    }
    // 读数据
    // 第一种
    // char buf[1024] = {0};
    // while (ifs >> buf)
    // {
    //     cout << buf << endl;
    // }
    // 第二种
    // char buf[1024] = {0};
    // while (ifs.getline(buf, sizeof(buf)))
    // {
    //     cout << buf << endl;
    // }

    // 第三种
    // string buf;
    // while (getline(ifs, buf))
    // {
    //     cout << buf << endl;
    // }
    // 第四种
    char c;
    // 一个字符一个字符的读取
    while ((c = ifs.get()) != EOF) // EOF==end of file
    {
        cout << c; // 会读到换行符不用自己写
    }

    ifs.close();
}

int main()
{
    test01();

    return 0;
}