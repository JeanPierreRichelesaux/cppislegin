#include<iostream>
#include<vector>
#include<ctime>
#include<chrono>

void qsort(std::vector<int>& v, int i, int j) {
    int i0 = i;
    int j0 = j;
    while(i != j) {
        if((v[i] > v[j]) == (j > i)) {
            std::swap(v[i], v[j]);
            std::swap(i, j);
        }
        i = i + int(j > i) * 2 - 1;
    }
    if(i0 != j0) {
        qsort(v, i0, std::max(i - 1, i0));
        qsort(v, std::min(i + 1, j0), j0);
    }
}

void hsort(std::vector<int>& v, int i, int j);

void step(std::vector<int>& v, int i, int j) {
    int i0 = i;
    int j0 = j;
    while(i != j) {
        if((v[i] > v[j]) == (j > i)) {
            std::swap(v[i], v[j]);
            std::swap(i, j);
        }
        i = i + int(j > i) * 2 - 1;
    }
    if(i0 != j0) {
        hsort(v, i0, std::max(i - 1, i0));
        hsort(v, std::min(i + 1, j0), j0);
    }
}

void insertsort(std::vector<int>& v, int i, int j) {
    for(int it = 1; it <= j; it++) {
        int x = it;
        while(x >= 1 && v[x] < v[x - 1]) {
            std::swap(v[x], v[x - 1]);
            x--;
        }
    }
}

void hsort(std::vector<int>& v, int i, int j) {
    if(j - i <= 9) {
        insertsort(v, i, j);
    } else {
        step(v, i, j);
    }
}

int main() {
    std::srand(std::time(0));
    std::vector<int> q1(100);
    std::vector<int> q2(1000);
    std::vector<int> q3(10000);
    for(int i = 0; i < 100; i++) {
        q1[i] = std::rand();
    }
    for(int i = 0; i < 1000; i++) {
        q2[i] = std::rand();
    }
    for(int i = 0; i < 10000; i++) {
        q3[i] = std::rand();
    }
    std::vector<int> h1 = q1;
    std::vector<int> h2 = q2;
    std::vector<int> h3 = q3;
    
    auto t0 = std::chrono::high_resolution_clock::now();
    qsort(q1, 0, q1.size() - 1);
    auto t1 = std::chrono::high_resolution_clock::now();
    hsort(h1, 0, h1.size() - 1);
    auto t2 = std::chrono::high_resolution_clock::now();
    std::cout << "100 элементов:\n"<< std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0) << " " << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1) << "\n\n";

    t0 = std::chrono::high_resolution_clock::now();
    qsort(q2, 0, q2.size() - 1);
    t1 = std::chrono::high_resolution_clock::now();
    hsort(h2, 0, h2.size() - 1);
    t2 = std::chrono::high_resolution_clock::now();
    std::cout << "1000 элементов:\n"<< std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0) << " " << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1) << "\n\n";
    
    t0 = std::chrono::high_resolution_clock::now();
    qsort(q3, 0, q3.size() - 1);
    t1 = std::chrono::high_resolution_clock::now();
    hsort(h3, 0, h3.size() - 1);
    t2 = std::chrono::high_resolution_clock::now();
    std::cout << "10000 элементов:\n"<< std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0) << " " << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1) << "\n\n";
}