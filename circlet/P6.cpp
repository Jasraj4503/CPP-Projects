#include <iostream>
using namespace std;

int main()
{
    for (int i = 5; i>=1; i--)
    {
        for (int j = 1; j <=5-i+1; j++)
        {
            cout << j << " ";
        }

        for (int space = 1; space <= 2 * (i - 1); space++)
        {
            cout << "  ";
        }

        for (int k = 5 - i + 1; k >= 1; k--)
        {
            cout << k << " ";
        }
        cout << endl;
    }
}