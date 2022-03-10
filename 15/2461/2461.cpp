#include <iostream.h>

long long n , s , i;
int a[100001];

int main()
{
    while (cin >> n)
    {
        if (n == 0) return 0;
        if (n == 2) {cout << "Impossible\n"; continue;}
        for (i = 1; i < n; i ++) a[i] = 1;
        for (i = 1; i < n; i ++)
        {
            s = i * i % n;
            a[s] = 0;
        }
        for (i = 1; i < n; i ++) cout << a[i];
        cout << endl;
    }
    return 0;
}
