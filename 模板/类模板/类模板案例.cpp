/*
案例描述: 实现一个通用的数组类，要求如下：

可以对内置数据类型以及自定义数据类型的数据进行存储
将数组中的数据存储到堆区
构造函数中可以传入数组的容量
提供对应的拷贝构造函数以及operator=防止浅拷贝问题
提供尾插法和尾删法对数组中的数据进行增加和删除
可以通过下标的方式访问数组中的元素
可以获取数组中当前元素个数和数组的容量
*/
#include <iostream>
#include "myArry.hpp"
#include <string>
void printIntArray(MyArry<int> &arr)
{
    for (int i = 0; i < arr.getSize(); i++)
    {
        cout << arr[i] << " ";
    }
}

void test01()
{
    MyArry<int> arr1(10);
    for (int i = 0; i < 10; i++)
    {
        arr1.Push_Back(i);
    }
    cout << "arr1的内容是：" << endl;
    printIntArray(arr1);
    cout << endl;
    cout << "arr1 的容量是：" << arr1.getCapacity() << endl;
    cout << "arr1 的元素个数是：" << arr1.getSize() << endl;
    cout << "---------------------------------------------------" << endl;
    arr1.Pop_Back();
    cout << "删除最后一个元素后arr1的内容是：" << endl;
    printIntArray(arr1);
    cout << endl;
    cout << "删除后arr1的容量是：" << arr1.getCapacity() << endl;
    cout << "删除后arr1的元素个数是：" << arr1.getSize() << endl;
    MyArry<int> arr2(arr1);
    MyArry<int> arr3(100);
    arr3 = arr1;
}
// 测试自定义数据类型
class Person
{
public:
    Person() {};
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

public:
    string m_Name;
    int m_Age;
};

void printPersonArray(MyArry<Person> &arr)
{
    for (int i = 0; i < arr.getSize(); i++)
    {
        cout << "姓名：" << arr[i].m_Name << " 年龄：" << arr[i].m_Age << endl;
    }
}
void test02()
{
    MyArry<Person> arr1(10); // 定义10个容量
    Person p1("孙悟空", 999);
    Person p2("猪八戒", 888);
    Person p3("沙和尚", 777);
    arr1.Push_Back(p1);
    arr1.Push_Back(p2);
    arr1.Push_Back(p3);
    cout << "arr1的内容是：" << endl;
    printPersonArray(arr1);
    cout << "arr1的容量是：" << arr1.getCapacity() << endl;
    cout << "arr1的元素个数是：" << arr1.getSize() << endl;
}
int main()
{
    // test01();
    test02();
    return 0;
}