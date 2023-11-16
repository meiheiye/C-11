#include <iostream>

using namespace std;

int main()
{
    volatile int a = 10;
    // 1.防止编译器优化
    // 2.确保每次访问都从内存中读取
}