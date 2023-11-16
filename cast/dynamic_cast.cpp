#include <iostream>

using namespace std;

class Father
{
public:
    virtual void f()
    {
        cout << "Father" << endl;
    }
};

class Son : public Father
{
public:
    void f()
    {
        cout << "Son" << endl;
    }
    int data;
};

int main()
{
    Father *pf;
    Son *ps;

    Father father;
    Son son;
    // 上行转换
    {
        ps = &son;
        pf = dynamic_cast<Father *>(ps);
        pf->f();
    }
    // 下行转换
    {
        pf = &son;
        ps = dynamic_cast<Son *>(pf);
        ps->f();
    }
}