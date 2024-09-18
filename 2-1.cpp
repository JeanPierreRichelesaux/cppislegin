#include <iostream>
using namespace std;

int isPrime(int x)
{
    bool isP = true;
    int maxdel;
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            isP = false;
            maxdel = x / i;
            break;
        }
    }
    if(isP)
    {
        return -1;
    }
    return maxdel;
}

int x;

int main()
{
    cin >> x;
    if(isPrime(x)< 0)
    {
        cout << "Prime!\n";
    }
    else
    {
    cout << isPrime(x) << "\n";
    }
}