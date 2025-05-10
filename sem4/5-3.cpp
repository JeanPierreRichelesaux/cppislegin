#include<iostream>
#include<vector>
#include<ctime>
#include<chrono>
#include<thread>

void merge(std::vector<int>& a, int beg, int mid, int end) {
    std::vector<int> help(end - beg, 0);
    int it1 = 0;
    int it2 = 0;

    while(beg + it1 < mid && mid + it2 < end) {
        if(a[beg + it1] < a[mid + it2]) {
            help[it1 + it2] = a[beg + it1];
            it1++;
        } else {
            help[it1 + it2] = a[mid + it2];
            it2++;
        }
    }
    while(beg + it1 < mid) {
        help[it1 + it2] = a[beg + it1];
        it1++;
    }
    while(mid + it2 < end) {
        help[it1 + it2] = a[mid + it2];
        it2++;
    }
    for(int i = 0; i < end - beg; i++) {
        a[beg + i] = help[i];
    }
}

void mergesort(std::vector<int>& a, int beg, int end) {
    if(beg + 1 < end) {
        int mid = (beg + end) / 2;
        mergesort(a, beg, mid);
        mergesort(a, mid, end);
        merge(a, beg, mid, end);
    }
}

void search(std::vector<int>& a, int beg, int end, int x, int& id) {
    for(int i = beg; i < end; i++) {
        if(a[i] == x){
            id = i;
            return;
        }
    }
    id = -1;
}

int comp(int a, int b) {
    if(a >= 0)
        return a;
    return b;
}

int main() {
    std::srand(std::time(0));
    std::vector<int> a(10000);
    for(int i = 0; i < 10000; i++) {
        a[i] = std::rand();
    }

    std::thread t1(mergesort, std::ref(a), 0, 2500);
    std::thread t2(mergesort, std::ref(a), 2500, 5000);
    std::thread t3(mergesort, std::ref(a), 5000, 7500);
    std::thread t4(mergesort, std::ref(a), 7500, 10000);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    merge(a, 0, 2500, 5000);
    merge(a, 5000, 7500, 10000);
    merge(a, 0, 5000, 10000);

    int x1 = a[7000];
    int i1 = -1;
    int i2 = -1;
    int i3 = -1;
    int i4 = -1;

    std::thread t5(search, std::ref(a), 0, 2500, x1, std::ref(i1));
    std::thread t6(search, std::ref(a), 2500, 5000, x1, std::ref(i2));
    std::thread t7(search, std::ref(a), 5000, 7500, x1, std::ref(i3));
    std::thread t8(search, std::ref(a), 7500, 10000, x1, std::ref(i4));

    t5.join();
    t6.join();
    t7.join();
    t8.join();

    std::cout << comp(comp(comp(i1, i2), i3), i4);
}