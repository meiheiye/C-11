#include <iostream>
using namespace std;

int main()
{
    {
        const int a = 1;
        // int *p = &a;  "const int *" 类型的值不能用于初始化 "int *" 类型的实体
        int *p = const_cast<int *>(&a);
        *p = 50;
        cout << a << endl;  // 1
        cout << *p << endl; // 50
    }
    {
        int a = 10;
        const int &b = a;
        // b = 20;  表达式必须是可修改的左值  常量引用，不允许修改值
        int &c = const_cast<int &>(b);
        c = 20;
        cout << a << endl; // 20
    }
}