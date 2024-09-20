#include <iostream>
using namespace std;

/**
 * *
 *  **优点1： **将所有成员属性设置为私有，可以自己控制读写权限

    **优点2： **对于写权限，我们可以检测数据的有效性
 *
 *
 *
 */
class Person
{

public:
    // 姓名设置可读可写 通过在public设置访问或设置函数来读取私有属性
    void setName(string name)
    {
        m_Name = name;
    }
    string getNmae()
    {
        return m_Name;
    }

private:
    string m_Name;
    int m_Age;
    string m_Lover;
};
int main()
{
    Person p;
    p.setName("张三");
    cout << "姓名：" << p.getNmae() << endl;
    return 0;
}