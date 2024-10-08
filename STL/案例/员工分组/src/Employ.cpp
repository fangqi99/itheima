#include "D:\clionproject\itheima\STL\案例\员工分组\include\Employ.h"

enum Department
{
	CHEHUA = 0,
	MEISHU,
	YANFA
};
Empolyee::Empolyee(string name, int salary)
{
	this->m_Name = name;
	this->m_Salary = salary;
}

void createEmployee(vector<Empolyee> &v)
{
	string nameSeed = "ABCDEEFGHIJ";
	for (int i = 0; i < 10; i++)
	{
		string name = "员工";
		name += nameSeed[i];
		int salary = rand() % 10001 + 10000; // 10000~20000
		Empolyee e(name, salary);
		v.push_back(e); // 将e对象放入到vector容器中
	}
}

void printEmployee(vector<Empolyee> &v)
{
	for (auto it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名：" << it->m_Name << "  " << "薪资：" << it->m_Salary << endl;
	}
	cout << endl;
}
// 员工分组
void setGroup(vector<Empolyee> &v, multimap<int, Empolyee> &m)
{
	for (auto it = v.begin(); it != v.end(); it++)
	{
		int detpID = rand() % 3; // 0,1,2
		m.insert(make_pair(detpID, *it));
	}
}
void showEmpByGroup(multimap<int, Empolyee> &m)
{
	cout << "策划部员工：" << endl;
	// 因为key是按照升序排序的，所以查找key为0的元素，就是第一个元素
	multimap<int, Empolyee>::iterator chehuaPose = m.find(CHEHUA); // 返回第一个位置的迭代器
	int count = m.count(CHEHUA);								   // 统计出key为0的元素的个数
	int index = 0;
	for (; chehuaPose != m.end() && index < count; chehuaPose++, index++)
	{
		cout << "姓名：" << chehuaPose->second.m_Name << "  " << "薪资：" << chehuaPose->second.m_Salary << endl;
	}
	cout << "美术部员工：" << endl;
	// 因为key是按照升序排序的，所以查找key为0的元素，就是第一个元素
	multimap<int, Empolyee>::iterator meishuPose = m.find(MEISHU); // 返回第一个位置的迭代器
	count = m.count(MEISHU);									   // 统计出key为0的元素的个数
	index = 0;
	for (; meishuPose != m.end() && index < count; meishuPose++, index++)
	{
		cout << "姓名：" << meishuPose->second.m_Name << "  " << "薪资：" << meishuPose->second.m_Salary << endl;
	}
	cout << "研发部员工：" << endl;
	// 因为key是按照升序排序的，所以查找key为0的元素，就是第一个元素
	multimap<int, Empolyee>::iterator yanfaPose = m.find(YANFA); // 返回第一个位置的迭代器
	count = m.count(YANFA);										 // 统计出key为0的元素的个数
	index = 0;
	for (; yanfaPose != m.end() && index < count; yanfaPose++, index++)
	{
		cout << "姓名：" << yanfaPose->second.m_Name << "  " << "薪资：" << yanfaPose->second.m_Salary << endl;
	}
}

void MyShowEmpByGroup(multimap<int, Empolyee> &m)
{

	int lastDepartment = -1; // 用于跟踪上一次输出的部门
	for (auto it = m.begin(); it != m.end(); it++)
	{
		// 检查当前部门是否和上一个部门相同，不同则输出部门名称
		if (it->first != lastDepartment)
		{
			lastDepartment = it->first; // 更新为当前部门

			switch (it->first)
			{
			case CHEHUA:
				cout << "策划部员工：" << endl;
				break;
			case MEISHU:
				cout << "美术部员工：" << endl;
				break;
			case YANFA:
				cout << "研发部员工：" << endl;
				break;
			default:
				continue; // continue 表示跳过当前循环的剩余部分，直接进入下一个循环的迭代。
			}
		}

		// 输出员工姓名和薪资
		cout << "姓名：" << it->second.m_Name << "  " << "薪资：" << it->second.m_Salary << endl;
	}
}
