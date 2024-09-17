#include <iostream>
using namespace std;

class BaseDrink
{
public:
    virtual void boilwater() = 0;
    virtual void chongpao() = 0;
    virtual void daorubeizhong() = 0;
    virtual void addsomething() = 0;

    // 第三种加一个内部成员函数制作流程
    void makeDrink()
    {
        boilwater();
        chongpao();
        daorubeizhong();
        addsomething();
    }
};

class chongCoffee : public BaseDrink
{
public:
    void boilwater()
    {
        cout << "煮水" << endl;
    }
    void chongpao()
    {
        cout << "冲泡咖啡" << endl;
    }
    void daorubeizhong()
    {
        cout << "倒入杯中" << endl;
    }
    void addsomething()
    {
        cout << "加糖和牛奶" << endl;
    }
};
class chongTea : public BaseDrink
{
public:
    void boilwater()
    {
        cout << "煮水" << endl;
    }
    void chongpao()
    {
        cout << "冲泡茶叶" << endl;
    }
    void daorubeizhong()
    {
        cout << "倒入杯中" << endl;
    }
    void addsomething()
    {
        cout << "加柠檬" << endl;
    }
};
// 第二种
//  写一个函数来实现
//  void makeDrink(BaseDrink *bd)
//  {
//      bd->boilwater();
//      bd->chongpao();
//      bd->daorubeizhong();
//      bd->addsomething();
//      delete bd;
//  }

void test01()
{
    // 第一种
    //  BaseDrink *bd = new chongCoffee;
    //  bd->boilwater();
    //  bd->chongpao();
    //  bd->daorubeizhong();
    //  bd->addsomething();
    //  delete bd;
    //  bd = new chongTea;
    //  bd->boilwater();
    //  bd->chongpao();
    //  bd->daorubeizhong();
    //  bd->addsomething();
    //  delete bd;

    // 第二种
    //  makeDrink(new chongCoffee);==BaseDrink *bd = new chongCoffee;
    //  makeDrink(new chongTea);

    // 第三种写法
    BaseDrink *bd = new chongCoffee;
    bd->makeDrink();
    bd->makeDrink();
    delete bd;
}

int main()
{
    test01();
    return 0;
}