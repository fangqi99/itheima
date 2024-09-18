#include <iostream>
using namespace std;

struct info
{
    uint8_t a;
    uint16_t b;
    uint8_t c;
};
struct alignas(16) info2
{
    // uint8_t a;
    // uint16_t b;
    // uint8_t c;
    int d;
    double e;
    long long f;
};
int main()
{
    info2 obj; // 创建结构体实例
    // cout << sizeof(info::a) << endl;
    // cout << sizeof(info::b) << endl;
    // cout << sizeof(info::c) << endl;
    // cout << sizeof(info) << endl;
    // cout << alignof(info) << endl;
    cout << "---------------------------------" << endl;
    // cout << sizeof(info2::a) << endl;
    // cout << sizeof(info2::b) << endl;
    // cout << sizeof(info2::c) << endl;
    cout << sizeof(info2::d) << endl;
    cout << sizeof(info2::e) << endl;
    cout << sizeof(info2::f) << endl;
    // 输出成员变量的地址
    cout << "Address of d: " << (&obj.d) << endl;
    cout << "Address of e: " << (&obj.e) << endl;
    cout << "Address of f: " << (&obj.f) << endl;

    cout << sizeof(info2) << endl;
    cout << alignof(info2) << endl;
    return 0;
}
