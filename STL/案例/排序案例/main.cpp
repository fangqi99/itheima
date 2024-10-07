#include <iostream>
#include "D:\clionproject\itheima\STL\案例\排序案例\include\Person.h"
using namespace std;

int main()
{
    cout << "****************普通版本如下：****************" << endl;
    list<Person> L;
    L = createList();
    cout << "-------------排序前-------------" << endl;
    showList(L);
    sortList(L);
    cout << "-------------排序后-------------" << endl;
    showList(L);
    cout << "****************指针版本如下：****************" << endl;
    // 用指针来维护
    list<Person> *Lptr = createListptr();
    cout << "-------------排序前-------------" << endl;
    showList(*Lptr); // 放进去也是解引用后的指针
    sortList(*Lptr);
    cout << "-------------排序后-------------" << endl;
    showList(*Lptr);
    // 因为这个指针是在creatListptr函数里new出来的，所以要delete
    delete Lptr;
    return 0;
}