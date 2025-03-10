#include<vector>
#include<iostream>


int hf(int x, int SIZE) {
    return x % SIZE;
}

struct Hash {
    std::vector<int> table;
    Hash(int size) : table(std::vector<int>(size)) {}

    void add(int x) {
        int it = hf(x, table.size());
        while(table[it] != 0) {
            it = (it + 1) % table.size();
        }
        table[it] = x;
    }

    int* search(int x) {
        int it = hf(x, table.size());
        while(table[it] != 0) {
            if(table[it] == x) {
                return &table[it];
            }
            it = (it + 1) % table.size();
        }
        return nullptr;
    }
};

int main() {
    int x;
    Hash a(20);
    for(int i = 0; i < 7; i++) {
        std::cin >> x;
        a.add(x);
    }
    for(auto it = a.table.begin(); it != a.table.end(); ++it) {
        if(*it) {
            std::cout << *it << " ";
        } else {
            std:: cout << "None ";
        }
    }
    std::cout << "\n";
}