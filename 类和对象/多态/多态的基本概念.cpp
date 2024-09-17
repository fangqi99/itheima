#include <iostream>
using namespace std;

/*
多态是C++面向对象三大特性之一
多态分为两类
静态多态: 函数重载 和 运算符重载属于静态多态，复用函数名
动态多态: 派生类和虚函数实现运行时多态

静态多态和动态多态区别：
静态多态的函数地址早绑定 - 编译阶段确定函数地址
动态多态的函数地址晚绑定 - 运行阶段确定函数地址
*/
class Animal
{
public:
    virtual void speak() // 加上virtual 变成虚函数地址晚绑定
    {
        cout << "动物在说话" << endl;
    }
};
class Cat : public Animal
{
public:
    void speak()
    {
        cout << "猫在说话" << endl;
    }
};
class Dog : public Animal
{
public:
    void speak()
    {
        cout << "狗在说话" << endl;
    }
};
// 地址早绑定，在编译阶段就确定了函数地址
// 如果想执行让猫说话得进行地址晚绑定，需要在运行阶段绑定
// 我们希望传入什么对象，那么就调用什么对象的函数
// 如果函数地址在编译阶段就能确定，那么静态联编
// 如果函数地址在运行阶段才能确定，就是动态联编
void dospeak(Animal &animal) // Ainmal &ainmal =cat
{
    animal.speak();
}
// 动态多态满足条件：
// 1、有继承关系
// 2、子类在写一遍父类中的虚函数，通过这个虚函数实现 子类中virtual可写可不写
// 动态多态使用：
// 父类指针或引用 指向子类对象
void test01()
{
    Cat cat;
    dospeak(cat); // 用父类引用接收子类对象
    Dog dog;
    dospeak(dog);
}
void test02()
{
    cout << "sizeof Animal " << sizeof(Animal) << endl;
}

int main()
{
    test01();
    test02();
    return 0;
}