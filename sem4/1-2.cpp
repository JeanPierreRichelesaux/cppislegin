#include<iostream>
#include<list>
#include<algorithm>

std::list<int> a{1, -7, -3, -12, 5, -3, 24, 117, -42};
std::list<int> pos;
std::list<int> neg;

void sort_ins(std::list<int>* b, int x) {
    bool f = true;
    for(auto it = b->begin(); it != b->end(); ++it) {
        if(*it > x) {
            b->insert(it--, x);
            f = false;
            break;
        }
    }
    if(f) {
        b->push_back(x);
    }
}

int main() {
    for(auto it = a.begin(); it != a.end(); ++it) {
        if(*it < 0) {
            sort_ins(&neg, *it);
        } else {
            sort_ins(&pos, *it);
        }
    }
    for(auto it = pos.begin(); it != pos.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
    for(auto it = neg.begin(); it != neg.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
}