#include<iostream>
using namespace std;

struct Vektor
{
    int n;
    float* coord;

    Vektor multiply(float k)
    {
        Vektor s{n, new float[n]};
        for(int i = 0; i < n; i++)
        {
            s.coord[i] = coord[i] * k;
        }
        return s;
    }

    Vektor summ(Vektor v2)
    {
        Vektor s{n, new float[n]};
        for(int i = 0; i < n; i++)
        {
            s.coord[i] = coord[i] + v2.coord[i];
        }
        return s;
    }

    int skpr(Vektor v2)
    {
        int summ = 0;
        for(int i = 0; i < n; i++)
        {
            summ += (coord[i] * v2.coord[i]);
        }
        return summ;
    }
};

int main()
{
    Vektor v1{2, new float[2]};
    v1.coord[0] = -1.5;
    v1.coord[1] = 4;
    Vektor v2{2, new float[2]};
    v2.coord[0] = 8;
    v2.coord[1] = 0;
    Vektor v3 = v1.multiply(2.5);
    Vektor v4 = v1.summ(v2);
    float skpr = v2.skpr(v1);
    for(int i = 0; i < v3.n; i++)
    {
        cout << v3.coord[i] << " ";
    }
    cout << "\n";
    for(int i = 0; i < v4.n; i++)
    {
        cout << v4.coord[i] << " ";
    }
    cout << "\n" << skpr << "\n";
}
