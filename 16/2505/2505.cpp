#include <iostream.h>
#include <stdio.h>

int main()
{
long long n , tot;
long long i , t;

    while (cin >> n)
    {
        t = 9; tot = 0;
        for (i = 0; i <= 500; i ++)
        {
            if (n > t) tot ++;
            else break;
        }
        if (tot % 2 == 0) cout << "Stan wins." << endl;
        else cout << "Ollie wins." << endl;
    }
    return 0;
}
