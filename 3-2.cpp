#include<iostream>
using namespace std;

float massiv[] = {1.5, 2.2, 3.0, 4.1, 5.9, 6.0, 7.5};

int search(int* m, int target, int length)
{
    for(int i = 0; i < length; i++)
    {
        if(m[i] == target)
        {
            return i;
            break;
        }
    }
    return -1;
}

int search(float* m, float target, int length)
{
    for(int i = 0; i < length; i++)
    {
        if(m[i] == target)
        {
            return i;
            break;
        }
    }
    return -1;
}

int search(char* m, char target, int length)
{
    for(int i = 0; i < length; i++)
    {
        if(m[i] == target)
        {
            return i;
            break;
        }
    }
    return -1;
}

int main()
{
    cout << search(massiv, 3.5, 7);
}