#include <iostream>
#include <thread>
#include <mutex>

int x;
std:: mutex lock;
void threadFunction1()
{
        for( int i = 0; i < 1000003; ++i ) {
                lock.lock();
                x++;
                lock.unlock();
        }
}

void threadFunction2()
{
        for( int i = 0; i < 1000000; ++i ) {
                lock.lock();
                if ( (x%2) == 0 ) {
                        std::cout << "x = " << x << std::endl;
                }
        lock.unlock();
        }

}

int main()
{
     std::thread t1(threadFunction1);
     std::thread t2(threadFunction2);
     t1.join();
     t2.join();
     return 0;
}
