#include <iostream>

/*作用：将一个基类对象指针（或引用）cast到继承类指针，dynamic_cast会根据基类指针是否真正指向继承类指针来做相应处理，
即会作出一定的判断*/
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
    // 上行转换     子类的指针转换成基类的指针
    {
        ps = &son;
        pf = dynamic_cast<Father *>(ps);
        pf->f();
    }

    // 下行转换     基类的指针转换成子类的指针
    {
        pf = &son;
        ps = dynamic_cast<Son *>(pf);
        ps->f();
    }
}