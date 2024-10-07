// 这里写类模板
#pragma once
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class MyArry
{
public:
    MyArry(int m_ArryCap)
    {
        // cout << "MyArry有参构造函数调用" << endl;
        this->m_ArryCap = m_ArryCap;
        this->m_ArrySize = 0;
        this->m_pArry = new T[this->m_ArryCap];
    }
    // 拷贝构造
    MyArry(const MyArry &arry)
    {
        // cout << "MyArry拷贝构造函数调用" << endl;
        this->m_ArryCap = arry.m_ArryCap;
        this->m_ArrySize = arry.m_ArrySize;

        this->m_pArry = new T[this->m_ArryCap]; // 深拷贝
        for (int i = 0; i < this->m_ArrySize; i++)
        {
            // 如果T为对象，而且还包含指针，必须需要重载 = 操作符，因为这个等号不是 构造 而是赋值，
            //  普通类型可以直接= 但是指针类型需要深拷贝
            this->m_pArry[i] = arry.m_pArry[i];
        }
    }
    // 重载= 操作符  防止浅拷贝问题
    MyArry &operator=(const MyArry &arry)
    {
        // cout << "MyArry重载=操作符调用" << endl;
        //  先判断原来堆区是否有数据，如果有先释放
        if (this->m_pArry != NULL)
        {
            delete[] this->m_pArry;
            this->m_pArry = NULL;
            this->m_ArryCap = 0;
            this->m_ArrySize = 0;
        }
        // 深拷贝
        this->m_ArryCap = arry.m_ArryCap;
        this->m_ArrySize = arry.m_ArrySize;
        this->m_pArry = new T[this->m_ArryCap];
        for (int i = 0; i < this->m_ArrySize; i++)
        {
            // 如果T为对象，而且还包含指针，必须需要重载 = 操作符，因为这个等号不是 构造 而是赋值，
            //  普通类型可以直接= 但是指针类型需要深拷贝
            this->m_pArry[i] = arry.m_pArry[i];
        }
        return *this;
    }

    // 尾插法
    void Push_Back(const T &value)
    {
        // 先判断容量是否等于大小
        if (this->m_ArryCap == this->m_ArrySize)
        {
            cout << "当前容量已满！" << endl;
            return; // 直接return 退出Push_Back函数
        }
        this->m_pArry[this->m_ArrySize] = value;
        // 更新数组的大小
        this->m_ArrySize++;
    }
    // 尾删法
    void Pop_Back()
    {
        if (this->m_ArrySize == 0)
        {
            cout << "当前数组无元素，无法删除！" << endl;
            return;
        }
        // 这样应该是直接删除
        // this->m_pArry[this->m_ArrySize] = NULL;
        //  让用户访问不到最后一个元素--逻辑上的尾删
        this->m_ArrySize--;
    }
    // 通过下标方式访问数组中的元素
    T &operator[](int index)
    {
        return this->m_pArry[index];
    }
    // 返回数组容量
    int getCapacity()
    {
        return this->m_ArryCap;
    }
    // 返回数组大小
    int getSize()
    {
        return this->m_ArrySize;
    }

    ~MyArry()
    {
        if (this->m_pArry != NULL)
        {
            delete[] this->m_pArry;
            this->m_pArry = NULL; // 防止野指针
        }
        // cout << "MyArry析构函数调用" << endl;
    }

private:
    T *m_pArry;     // 指向堆区开辟的真实的数组的指针
    int m_ArryCap;  // 数组的容量
    int m_ArrySize; // 数组的大小--实际元素的个数
};
