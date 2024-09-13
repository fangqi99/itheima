#include <iostream>

using namespace std;

int main()
{
    struct student
    {
        string name;
        int age;
        string address;
    };
    int num = 1;
    while (num <= 5)
    {
        struct student stu;
        cout << "正在录入学生" << num << "的信息:" << endl;
        cout << "请输入姓名：";
        cin >> stu.name;
        cout << "请输入年龄：";
        cin >> stu.age;
        cout << "请输入地址：";
        cin >> stu.address;

        cout << "学生" << num << "信息核对：姓名：" << stu.name << "年龄：" << stu.age << "地址：" << stu.address << endl;
        num++;
    }

    return 0;
}