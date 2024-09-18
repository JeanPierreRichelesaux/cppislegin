#include <iostream>
using namespace std;

int length;

int main()
{
    cin >> length;
    int* massiv = new int[length];
    delete[] massiv;
}