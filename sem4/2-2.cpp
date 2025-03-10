#include<map>
#include<iostream>
#include<string>

class Book {
    std::map<std::string, int> numbers;

  public:
    void add(std::string name, int num) {
        numbers[name] = num;
    }

    void del(std::string name) {
        for(auto it = numbers.begin(); it != numbers.end(); ++it) {
            if(it->first == name) {
                numbers.erase(it);
                break;
            }
        }
    }

    bool search(std::string name) {
        for(auto it = numbers.begin(); it != numbers.end(); ++it) {
            if(it->first == name) {
                return true;
            }
        }
        return false;
    }

    void printall() {
        for(auto it = numbers.begin(); it != numbers.end(); ++it) {
            std::cout << it->first << " " << it->second << "\n";
        }
    }
};

int main() {
    Book a;
    a.add("Daniel", 555);
    a.add("Simon", 123);
    a.add("Andrew", 117);
    a.printall();
    std::cout << "!!!\n";
    if(a.search("Daniel")) { std::cout << "Daniel is here!\n";}
    a.del("Daniel");
    a.printall();
    if(a.search("Daniel")) { std::cout << "Daniel is here!\n";}
}