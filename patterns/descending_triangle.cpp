#include <iostream>

using namespace std;

int main()
{
    for(int i = 4; i >= 1; i--)
        {
            for(int j = i; j >= 1; j--)
                cout << "*";
            cout << "\n";
        }
    return 0;
}