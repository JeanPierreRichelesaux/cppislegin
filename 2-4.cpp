#include <iostream>
#include<string>
using namespace std;

string longstr;
string shortstr;
int kol;

int main()
{
    cin >> longstr;
    cin >> shortstr;
    for(int i = 0; i < longstr.size() - shortstr.size() + 1; i++)
    {
        if(shortstr == longstr.substr(i, shortstr.size()))
        {
            kol++;
        }
    }
    cout << kol << "\n";
}