#include <iostream>
using namespace std;

int summ;
int x;

int main()
{
    cin >> x;
    while(x != 0)
    {
        if(x > 0)
        {
            summ += x;
        }
        cout << summ << "\n";
        cin >> x;
    }
}
