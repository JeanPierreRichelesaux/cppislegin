#include <iostream>
using namespace std;

int length;
int summa;

int main()
{
    cin >> length;
    int* massiv = new int[length];
    for(int i = 0; i < length; i++)
    {
        *(massiv + i) = i * i;
        summa += massiv[i];
    }
    cout << summa << "\n";
    delete[] massiv;
}
