#include <iostream>
using namespace std;

// 普通实现
class Calculator
{
public:
    Calculator(int num1, int num2)
    {
        this->m_num1 = num1;
        this->m_num2 = num2;
    }
    int getResult(string oper)
    {
        if (oper == "+")
        {
            return m_num1 + m_num2;
        }
        else if (oper == "-")
        {
            return m_num1 - m_num2;
        }
        else if (oper == "*")
        {
            return m_num1 * m_num2;
        }
        // 如果要提供新的运算，需要修改源码 else if (oper == "/"){};
        // 在真实的开发中，我们一般不会修改源码，而是通过多态的方式，让基类指针指向派生类对象
        // 即 开闭原则:对扩展进行开发，对修改进关闭
    }
    int m_num1;
    int m_num2;
};

// 利用多态实现计算器
// 多态优点：代码组织结构清晰，可读性强，利于前期和后期的扩展以及维护
//  实现计算器的基类
class AbstractCalculator
{
public:
    virtual int getResult()
    {
        return 0;
    }
    int m_num1;
    int m_num2;
};
// 加法计算器类
class AddCalculator : public AbstractCalculator
{
public:
    int getResult()
    {
        return m_num1 + m_num2;
    }
};
// 减法计算器类
class SubCalculator : public AbstractCalculator
{
public:
    int getResult()
    {
        return m_num1 - m_num2;
    }
};
// 乘法计算器类
class MulCalculator : public AbstractCalculator
{
public:
    int getResult()
    {
        return m_num1 * m_num2;
    }
};
// 除法计算器类
class DivCalculator : public AbstractCalculator
{
public:
    int getResult()
    {
        return m_num1 / m_num2;
    }
};

void test01()
{
    Calculator c1(10, 20);
    cout << c1.m_num1 << "+" << c1.m_num2 << "=" << c1.getResult("+") << endl;
    cout << c1.m_num1 << "-" << c1.m_num2 << "=" << c1.getResult("-") << endl;
    cout << c1.m_num1 << "*" << c1.m_num2 << "=" << c1.getResult("*") << endl;
}
void test02()
{
    // 多态使用条件
    // 父类指针或引用 指向子类对象
    AbstractCalculator *abc = new AddCalculator; // 在堆区开辟一个内存存放子类对象并返回一个指向该对象的指针，然后让父类指针abc指向这个内存
    abc->m_num1 = 10;
    abc->m_num2 = 20;
    cout << abc->m_num1 << "+" << abc->m_num2 << "=" << abc->getResult() << endl;
    delete abc; // 用完了记得销毁
    // 减法计算器
    abc = new SubCalculator;
    abc->m_num1 = 10;
    abc->m_num2 = 20;
    cout << abc->m_num1 << "-" << abc->m_num2 << "=" << abc->getResult() << endl;
    delete abc;
    // 乘法计算器
    abc = new MulCalculator;
    abc->m_num1 = 10;
    abc->m_num2 = 20;
    cout << abc->m_num1 << "*" << abc->m_num2 << "=" << abc->getResult() << endl;
    delete abc;
    // 除法计算器
    abc = new DivCalculator;
    abc->m_num1 = 10; // 10/20=0
    abc->m_num2 = 20;
    cout << abc->m_num1 << "/" << abc->m_num2 << "=" << abc->getResult() << endl;
    delete abc;
}
int main()
{
    // test01();
    test02();
    return 0;
}