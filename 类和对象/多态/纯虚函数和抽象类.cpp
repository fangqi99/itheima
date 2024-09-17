#include <iostream>
using namespace std;
// 在多态中，通常父类中虚函数的实现是毫无意义的，主要都是调用子类重写的内容
// 因此可以将虚函数改为纯虚函数
// 当类中有了纯虚函数，这个类也称为抽象类
/*
抽象类特点：
无法实例化对象
子类必须重写抽象类中的纯虚函数，否则也属于抽象类
*/
class Base
{
public:
    // 纯虚函数
    //  类中只要有一个纯虚函数就称为抽象类
    //  抽象类无法实例化对象
    //  子类必须重写父类中的纯虚函数，否则也属于抽象类
    virtual void speak() = 0; // 纯虚函数
};

class Son : public Base
{
public:
    // 重写父类中的纯虚函数，否则也属于抽象类
    void speak()
    {
        cout << "son speak" << endl;
    }
};
void test01()
{
    // Base b;//抽象类无法实例化对象
    // new Base//抽象类无法实例化对象
    Base *base = new Son;
    base->speak();
    delete base; // 记得销毁
}
int main()
{

    test01();
    return 0;
}