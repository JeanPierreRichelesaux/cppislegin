#include<iostream>
#include<thread>

int a[2500];

void fill500(int start) {
    for(int i = start; i < start + 500; i++) {
        a[i] = std::rand();
    }
}

int main() {
    std::srand(std::time(0));

    std::thread t1(fill500, 0);
    std::thread t2(fill500, 500);
    std::thread t3(fill500, 1000);
    std::thread t4(fill500, 1500);
    std::thread t5(fill500, 2000);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
}