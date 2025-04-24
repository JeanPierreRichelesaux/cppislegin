#include<iostream>
#include<thread>
#include<set>

int COUNTER;

void f() {
    COUNTER++;
    std::cout << "This thread ID is " << std::this_thread::get_id() << "\n";
    std::cout << "The number of threads is " << COUNTER << "\n";
    std::cout << "Hello world!\n";
    COUNTER--;
}

int main() {
    std::thread t1(f);
    std::thread t2(f);
    std::thread t3(f);
    std::thread t4(f);
    std::thread t5(f);
    std::thread t6(f);
    std::thread t7(f);
    std::thread t8(f);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    t7.join();
    t8.join();
}