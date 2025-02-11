#include<iostream>
#include<map>
#include<string>
#include<set>
#include<sstream>

std::string text;
std::map<std::string, int> count;
std::string word;
std::set<std::string> keys;

int main() {
    std::string str;
    getline(std::cin, str);
    std::istringstream iss(str);
    std::string word;
    while (iss >> word) {
        count[word]++;
        keys.insert(word);
    }
    auto max_it = keys.begin();
    for(auto it = keys.begin(); it != keys.end(); ++it) {
        if(count[*it] > count[*max_it]) {
            max_it = it;
        }
    }
    std::cout << *max_it;
}