#include <iostream>
#include <utility>
#include <unistd.h>
#include <future>
#include <thread>
#include <vector>
#include <mutex>

using namespace std;

vector<thread> v_thread;
mutex g_lock;

void func()
{
    lock_guard<mutex> locker(g_lock);
    for (int i = 0; i < 20; i++)
    {
        cout << i << " ";
    }
    cout << endl;
    this_thread::sleep_for(chrono::seconds(1));
}

int main()
{
    for (int i = 0; i < 3; i++)
    {
        thread t(func);
        v_thread.push_back(move(t));
    }
    for (auto &t : v_thread)
    {
        t.join();
    }
}