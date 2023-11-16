#include <iostream>
#include <condition_variable>
#include <thread>
#include <mutex>

using namespace std;

std::condition_variable cv;
std::mutex m_mutex;

bool data_ready = false;

void produce()
{
    while (1)
    {
        unique_lock<mutex> locker(m_mutex);
        cv.wait(locker, []
                { return !data_ready; });
        data_ready = true;
        cout << "produce ..." << endl;
        cv.notify_one();
        this_thread::sleep_for(chrono::seconds(1));
    }
}

void consum()
{
    while (1)
    {
        unique_lock<mutex> locker(m_mutex);
        cv.wait(locker, []
                { return data_ready; });
        data_ready = false;
        cout << "consume ..." << endl;
        cv.notify_one();
        this_thread::sleep_for(chrono::seconds(1));
    }
}
int main()
{
    thread t1(produce);
    thread t2(consum);

    t1.join();
    t2.join();
}