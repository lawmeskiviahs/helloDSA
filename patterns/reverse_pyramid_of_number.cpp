#include <iostream>

using namespace std;

int main()
{
    int z = 5;
    for(int i = 1; i < z; i++)
        {
            for(int j = 1; j <= i; j++)
                cout << j;
            for(int j = 0; j <2*(z-i-1); j++)
                cout << " ";
            for(int j = i ; j > 0; j--)
                cout << j;
            cout << "\n";
        }
    return 0;
}