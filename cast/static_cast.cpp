#include <iostream>

using namespace std;

int main()
{
    double a = 1.999;
    int b = static_cast<double>(a);
    cout << b << endl;
}