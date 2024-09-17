#include <iostream>
using namespace std;

/*
多态使用时，如果子类中有属性开辟到堆区，那么父类指针在释放时无法调用到子类的析构代码

解决方式：将父类中的析构函数改为虚析构或者纯虚析构

虚析构和纯虚析构共性：
可以解决父类指针释放子类对象
都需要有具体的函数实现

虚析构和纯虚析构区别：
如果是纯虚析构，该类属于抽象类，无法实例化对象 如果只有虚析构，没有其他虚函数，则可以实例化对象
*/
class Animal
{
public:
    Animal()
    {
        cout << "Animal 构造函数调用！" << endl;
    }
    virtual void Speak() = 0; // 纯虚函数

    // 注意无论是虚析构还是纯虚析构，都需要有具体实现
    //  析构函数加上virtual关键字，变成虚析构函数
    // virtual ~Animal() // 利用虚析构可以解决父类指针释放子类对象时不干净的问题
    // {
    //     cout << "Animal虚析构函数调用！" << endl;
    // }
    // 纯虚析构
    // 纯虚析构函数的类也是一个抽象类。不能够被实例化。
    virtual ~Animal() = 0;
};
Animal::~Animal() // 纯虚析构的实现
{
    cout << "Animal 纯虚析构函数调用！" << endl;
}
// 和包含普通纯虚函数的类一样，包含了纯虚析构函数的类也是一个抽象类。不能够被实例化。
class Cat : public Animal
{
public:
    Cat(string name)
    {
        cout << "Cat构造函数调用！" << endl;
        m_Name = new string(name); // 这里实现创建在堆区  记得在析构里释放
    }
    virtual void Speak()
    {
        cout << *m_Name << "小猫在说话!" << endl;
    }
    ~Cat()
    {
        if (this->m_Name != NULL)
        {
            cout << "Cat析构函数调用!" << endl;
            delete m_Name;
            m_Name = NULL;
        }
    }

public:
    string *m_Name; // 让小猫的名字创建在堆区，用这个指针去维护它
};
void test01()
{
    Animal *animal = new Cat("Tom");
    animal->Speak();

    // 通过父类指针去释放，会导致子类对象可能清理不干净，造成内存泄漏
    // 怎么解决？给基类增加一个虚析构函数
    // 虚析构函数就是用来解决通过父类指针释放子类对象
    delete animal;
}
int main()
{
    test01();
    return 0;
}