#include<string>
#include<deque>
#include<iostream>

class Taskbook;

class Task {
  friend Taskbook;

    std::string desc;
    bool vip;

    Task(std::string d, bool v) : desc(d), vip(v) {};
};

class Taskbook {
    std::deque<Task> q;

  public:
    void add(std::string d, bool v) {
        Task x = Task(d, v);
        if(v) {
            q.push_front(x);
        } else {
            q.push_back(x);
        }
    }

    void deal() {
        std::cout << "Task done: " << q[0].desc << "\n";
        q.pop_front();
    }

    void how_many() {
        int n = q.size();
        if(n != 0) {
            std::cout << n << " tasks left\n";
        } else {
            std::cout << "All tasks completed!\n";
        }
    }
};

int main() {
    Taskbook a;
    a.add("matan", true);
    a.add("physics", false);
    a.add("cpp", true);
    a.how_many();
    a.deal();
    a.deal();
    a.how_many();
    a.deal();
    a.how_many();
}