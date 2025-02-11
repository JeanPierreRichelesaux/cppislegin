#include<iostream>
#include<vector>
#include<set>
#include<string>

template <typename T>
void Print(T cont, std::string sep) {
    for(auto it = cont.begin(); it != cont.end(); ++it) {
        std::cout << *it;
        if(it != cont.end()--) {
            std::cout << sep;
        }
    }
    std::cout << "\n";
}

std::set<int> cont1{1, 7, 0, 2};
std::vector<char> cont2{'N', 'i', 'k', 'o', 'l', 'a', 'y', '!'};

int main() {
    Print(cont1, "");
    Print(cont2, " ");
}