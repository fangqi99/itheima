#include <iostream>
using namespace std;

const double Pi = 3.14;
class Circle
{
public:
    double r;
    double area()
    {
        return Pi * r * r;
    }
    double zhouchang()
    {
        return 2 * Pi * r;
    }
};

class Student
{
public:
    int id;
    string m_name;
    void print_info()
    {
        cout << id << " " << m_name << endl;
    }
    void setName(string name)
    {
        m_name = name;
    }
};

int main()
{

    Circle c1;
    c1.r = 10;
    cout << c1.area() << endl;
    cout << c1.zhouchang() << endl;
    Student s1;
    s1.id = 1;
    s1.setName("张三");
    s1.print_info();
    return 0;
}