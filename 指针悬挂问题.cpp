#include <iostream>
using namespace std;

int main()
{
    int *p1 = new int;
    *p1 = 10;
    int *p2 = p1;
    delete p1;
    cout << p1 << " " << p2 << endl;
    cout << *p1 << " " << *p2 << endl;
    return 0;
}