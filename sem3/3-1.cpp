#include<iostream>
using namespace std;

bool dynstat = false;

#if dynstat
  #define DYNAMIC_MEMORY(length) \
  int[length] massiv
#else 
  #define DYNAMIC_MEMORY(length) \
  int* massiv = new int[length]
#endif

void func(int*& m, int length)
{
    for(int i = 0; i < length; i++)
    {
        m[i] = i;
    }
    for(int i = 0; i < length; i++)
    {
        cout << m[i] << " ";
    }
}

int main()
{
    DYNAMIC_MEMORY(5);
    func(massiv, 5);
}
