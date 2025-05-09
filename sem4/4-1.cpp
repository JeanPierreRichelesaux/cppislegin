#include<iostream>
#include<vector>
#include<ctime>
#include<chrono>

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

void bubblesort(std::vector<int>* v) {
    for(int j = 0; j < v->size() - 1; j++) {
        for(int i = 0; i < v->size() - 1; ++i) {
            if((*v)[i] > (*v)[i + 1]) {
                std::swap((*v)[i], (*v)[i + 1]);
            }
        }
    }
}

void selectsort(std::vector<int>& a) {
    for(int i = 0; i < a.size() - 1; i++) {
        int min = i;
        for(int j = i + 1; j < a.size(); j++) {
            if(a[j] < a[min]) min = j;
        }
        std::swap(a[i], a[min]);
    }
}

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

int main() {
    std::srand(std::time(0));
    std::vector<int> q1(1000);
    std::vector<int> q2(5000);
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
    std::vector<int> b1 = q1;
    std::vector<int> b2 = q2;
    std::vector<int> b3 = q3;
    std::vector<int> m1 = q1;
    std::vector<int> m2 = q2;
    std::vector<int> m3 = q3;
    std::vector<int> s1 = q1;
    std::vector<int> s2 = q2;
    std::vector<int> s3 = q3;
    std::cout << "quick | bubble | merge | selection\n";

    auto t0 = std::chrono::high_resolution_clock::now();
    qsort(q1, 0, q1.size() - 1);
    auto t1 = std::chrono::high_resolution_clock::now();
    bubblesort(&b1);
    auto t2 = std::chrono::high_resolution_clock::now();
    mergesort(m1, 0, m1.size());
    auto t3 = std::chrono::high_resolution_clock::now();
    selectsort(s1);
    auto t4 = std::chrono::high_resolution_clock::now();
    std::cout << "1000 элементов:\n"<< std::chrono::duration_cast<std::chrono::milliseconds>(t1 - t0) << " | " << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1) << " | " << std::chrono::duration_cast<std::chrono::milliseconds>(t3 - t2) << " | " << std::chrono::duration_cast<std::chrono::milliseconds>(t4 - t3) <<"\n\n";

    t0 = std::chrono::high_resolution_clock::now();
    qsort(q2, 0, q2.size() - 1);
    t1 = std::chrono::high_resolution_clock::now();
    bubblesort(&b2);
    t2 = std::chrono::high_resolution_clock::now();
    mergesort(m2, 0, m2.size());
    t3 = std::chrono::high_resolution_clock::now();
    selectsort(s2);
    t4 = std::chrono::high_resolution_clock::now();
    std::cout << "5000 элементов:\n"<< std::chrono::duration_cast<std::chrono::milliseconds>(t1 - t0) << " | " << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1) << " | " << std::chrono::duration_cast<std::chrono::milliseconds>(t3 - t2) << " | " << std::chrono::duration_cast<std::chrono::milliseconds>(t4 - t3) <<"\n\n";

    t0 = std::chrono::high_resolution_clock::now();
    qsort(q3, 0, q3.size() - 1);
    t1 = std::chrono::high_resolution_clock::now();
    bubblesort(&b3);
    t2 = std::chrono::high_resolution_clock::now();
    mergesort(m3, 0, m3.size());
    t3 = std::chrono::high_resolution_clock::now();
    selectsort(s3);
    t4 = std::chrono::high_resolution_clock::now();
    std::cout << "10000 элементов:\n"<< std::chrono::duration_cast<std::chrono::milliseconds>(t1 - t0) << " | " << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1) << " | " << std::chrono::duration_cast<std::chrono::milliseconds>(t3 - t2) << " | " << std::chrono::duration_cast<std::chrono::milliseconds>(t4 - t3) <<"\n\n";

    std::cout << "Вывод:\nНа малых массивах bubble < selection < quick < merge\nНа больших массивах bubble < selection < merge < quick";
}