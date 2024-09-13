//
// Created by 27140 on 24-9-3.
//
#include <iostream>
using namespace std;

int main()
{
  int line = 1;
  while (line < 10)
  {
    int num = 1;
    while (num <= line)
    {
      cout << num << "*" << line << "=" << line * num << "\t";
      num++;
    }
    line++;
    cout << endl;
  }
  cout << "完成" << endl;
  return 0;
}