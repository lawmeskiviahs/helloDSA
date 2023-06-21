#include <iostream>

using namespace std;

int main()
{
    int z = 1;
    for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j <= i; j++)
                {
                    cout << z;
                    cout << " ";
                    z++;
                }
            cout << "\n";
        }
    return 0;
}