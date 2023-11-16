#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

timed_mutex g_mutex;

void func()
{
    std::chrono::milliseconds timeout(100);

    while (true)
    {
        if (g_mutex.try_lock_for(timeout)) // 允许线程在获取锁时等待一定的时间
        {
            cout << this_thread::get_id() << "get" << endl;
            chrono::milliseconds sleepDuration(250);
            this_thread::sleep_for(sleepDuration);
            g_mutex.unlock();
            this_thread::sleep_for(sleepDuration);
        }
        else // 放弃锁的获取而继续执行其他操作
        {
            cout << this_thread::get_id() << " dont get " << endl;
            chrono::milliseconds sleepDuration(250);
            this_thread::sleep_for(sleepDuration);
        }
    }
}

int main()
{
    thread t1(func);
    thread t2(func);
    t1.join();
    t2.join();
}