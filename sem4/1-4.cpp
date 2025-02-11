#include<iostream>
#include<stack>
#include<string>
#include<vector>
#include<map>
#include<stack>
#include<algorithm>

std::string s;
bool good = true;
std::vector<char> lefts {'[', '{', '('};
std::map<char, char> rights = {{'{', '}'}, {'(', ')'}, {'[', ']'}};
std::stack<char> order;

int main() {
    std::cin >> s;
    for(auto it = s.begin(); it != s.end(); ++it) {
        if(std::find(lefts.begin(), lefts.end(), *it) != lefts.end()) {
            order.push(*it);
        } else {
            if(order.empty() || *it != rights[order.top()]) {
                good = false;
                break;
            }
            order.pop();
        }
    }
    if(not order.empty()) {
        good = false;
    }
    if(good) {
        std::cout << "The sequence is right!";
    } else {
        std::cout << "The sequence is wrong!";
    }
}