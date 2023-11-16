#include <iostream>
#include <atomic>
#include <thread>

using namespace std;

atomic<int> value(0);
int tmp = 0;

void add()
{
    for (int i = 0; i < 10000000; i++)
    {
        // 引入竞争条件
        value++;
        tmp++;
    }
}

void decre()
{
    for (int i = 0; i < 10000000; i++)
    {
        // 引入竞争条件
        value--;
        tmp--;
    }
}

int main()
{
    thread t1(add);
    thread t2(decre);
    t1.join();
    t2.join();

    // 观察竞争状态
    cout << "Final value: " << value << endl;
    cout << "Final tmp: " << tmp << endl;

    return 0;
}
