#include<iostream>
#include<vector>
#include<ctime>
#include<chrono>

void bub(std::vector<int>* v) {
    for(int j = 0; j < v->size() - 1; j++) {
        for(int i = 0; i < v->size() - 1; ++i) {
            if((*v)[i] > (*v)[i + 1]) {
                std::swap((*v)[i], (*v)[i + 1]);
            }
        }
    }
}

void opt_bub(std::vector<int>* v) {
    bool f = true;
    while(f) {
        f = false;
        for(int i = 0; i < v->size() - 1; ++i) {
            if((*v)[i] > (*v)[i + 1]) {
                f = true;
                std::swap((*v)[i], (*v)[i + 1]);
            }
        }
    }
}



int main() {
    std::srand(std::time(0));
    std::vector<int> a1(100);
    std::vector<int> b1(1000);
    std::vector<int> c1(10000);
    for(int i = 0; i < 100; i++) {
        a1[i] = std::rand();
    }
    for(int i = 0; i < 1000; i++) {
        b1[i] = std::rand();
    }
    for(int i = 0; i < 10000; i++) {
        c1[i] = std::rand();
    }
    std::vector<int> a2 = a1;
    std::vector<int> b2 = b1;
    std::vector<int> c2 = c1;
    auto t0 = std::chrono::high_resolution_clock::now();
    bub(&a1);
    auto t1 = std::chrono::high_resolution_clock::now();
    opt_bub(&a2);
    auto t2 = std::chrono::high_resolution_clock::now();
    std::cout << "100 элементов:\n"<< t1 - t0 << " " << t2 - t1 << "\n";

    t0 = std::chrono::high_resolution_clock::now();
    bub(&b1);
    t1 = std::chrono::high_resolution_clock::now();
    opt_bub(&b2);
    t2 = std::chrono::high_resolution_clock::now();
    std::cout << "1000 элементов:\n"<< t1 - t0 << " " << t2 - t1 << "\n";
    
    t0 = std::chrono::high_resolution_clock::now();
    bub(&c1);
    t1 = std::chrono::high_resolution_clock::now();
    opt_bub(&c2);
    t2 = std::chrono::high_resolution_clock::now();
    std::cout << "10000 элементов:\n"<< t1 - t0 << " " << t2 - t1 << "\n";
}