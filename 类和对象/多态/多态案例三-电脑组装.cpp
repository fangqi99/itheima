#include <iostream>
using namespace std;
// 如果子类里new了新对象，就要用虚析构来来解决通过父类指针释放子类对象

class CPU
{
public:
    virtual void caluculate() = 0;
};

class GPU
{
public:
    virtual void display() = 0;
};

class Memory
{
public:
    virtual void storage() = 0;
};

class Computer
{
public:
    Computer(CPU *cpu, GPU *gpu, Memory *memory)
    {
        m_cpu = cpu;
        m_gpu = gpu;
        m_memory = memory;
    }
    // 工作函数
    void work()
    {
        // 让零件工作起来，调用接口
        m_cpu->caluculate();
        m_gpu->display();
        m_memory->storage();
    }
    // 提供析构函数，释放电脑的三个零件
    ~Computer()
    {
        if (m_cpu != NULL)
        {
            delete m_cpu;
            m_cpu = NULL;
        }
        if (m_gpu != NULL)
        {
            delete m_gpu;
            m_gpu = NULL;
        }
        if (m_memory != NULL)
        {
            delete m_memory;
            m_memory = NULL;
        }
    }

private:
    //  创建指针的原因是，这些都是抽象类，不能直接创建对象，需要用指针找到子类
    CPU *m_cpu;       // cpu零件的指针
    GPU *m_gpu;       // gpu零件的指针
    Memory *m_memory; // memory零件的指针
};

// 具体厂商
class IntelCPU : public CPU
{
public:
    void caluculate()
    {
        cout << "Intel CPU计算" << endl;
    }
};
class IntelGPU : public GPU
{
public:
    void display()
    {
        cout << "Intel GPU显示" << endl;
    }
};
class IntelMemory : public Memory
{
public:
    void storage()
    {
        cout << "Intel Memory存储" << endl;
    }
};

class LenvoCPU : public CPU
{
public:
    void caluculate()
    {
        cout << "Lenvo CPU计算" << endl;
    }
};

class LenvoGPU : public GPU
{
public:
    void display()
    {
        cout << "Lenvo GPU显示" << endl;
    }
};
class LenvoMemory : public Memory
{
public:
    void storage()
    {
        cout << "Lenvo Memory存储" << endl;
    }
};

void test01()
{
    cout << "第一台电脑开始工作" << endl;
    // 组装第一台电脑的零件  //零件都是new 记得释放
    CPU *Intelcpu = new IntelCPU; // 创建InterCPU指针
    GPU *Intelgpu = new IntelGPU;
    Memory *Intelmemory = new IntelMemory;
    // 创建第一台电脑
    // 创建了电脑对象，可以在电脑的析构函数中释放零件内存
    Computer *computer1 = new Computer(Intelcpu, Intelgpu, Intelmemory); // 创建一个指针去维护在堆区开辟的内存
    computer1->work();
    delete computer1;
    cout << "---------------------------------" << endl;
    cout << "第二台电脑开始工作" << endl;
    // 创建第二台电脑
    Computer *computer2 = new Computer(new LenvoCPU, new LenvoGPU, new LenvoMemory); // 直接new 进去
    computer2->work();
    delete computer2;
    cout << "---------------------------------" << endl;
    cout << "第三台电脑开始工作" << endl;
    // 创建第三台电脑
    Computer *computer3 = new Computer(new LenvoCPU, new IntelGPU, new LenvoMemory); // 直接new 进去
    computer3->work();
    delete computer3;
}

int main()
{
    test01();
    return 0;
}