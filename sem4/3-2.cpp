#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include<set>

std::map<std::string, std::set<std::string>> tree;
std::set<std::string> all;
std::set<std::string> kids;
std::map<std::string, int> depth;

void dfs(std::string curr, int dp) {
    depth[curr] = dp;
    for(auto it = tree[curr].begin(); it != tree[curr].end(); ++it) {
        dfs(*it, dp + 1);
    }
}

int main() {
    std::ifstream fin("input.txt");

    std::string child;
    std::string adult;
    int n;
    std::string dedus;

    fin >> n;
    for (int i = 0; i < n; ++i) {
        fin >> child >> adult;
        all.insert(child);
        all.insert(adult);
        kids.insert(child);
        if(tree.contains(adult)) {
            tree[adult].insert(child);
        } else {
            tree[adult] = std::set{child};
        }
    }
    for(auto it = all.begin(); it != all.end(); ++it) {
        if(kids.find(*it) == kids.end()) {
            dedus = *it;
            break;
        }
    }
    dfs(dedus, 0);
    for(auto it = all.begin(); it != all.end(); ++it) {
        std::cout << *it << " " << depth[*it] << "\n";
    }
}