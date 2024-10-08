#include "D:\clionproject\itheima\STL\案例\员工分组\include\Employ.h"
int main()
{
    // 1.创建员工
    vector<Empolyee> vEm;
    createEmployee(vEm);
    // 测试
    printEmployee(vEm);
    // 2.分组
    multimap<int, Empolyee> mEm;
    setGroup(vEm, mEm);
    showEmpByGroup(mEm);
    MyShowEmpByGroup(mEm);

    return 0;
}