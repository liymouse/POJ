#include <iostream.h>

int a[8];
int s[22] , t[22] , num[22] , b[22];
int m , n , k;
int total , max;

void find(int x)
{
int i , j , bo;

    if (x == k)
    {
        total = 0;
        for (i = 0; i < k; i ++)
            if (b[i]) total += (t[i] - s[i]) * num[i];
        if (total > max) max = total;
        return;
    }
    bo = 0;
    for (i = s[x]; i < t[x]; i ++)
    {
        a[i] += num[x];
		if (a[i] > m) bo = 1;
    }
    if (bo == 0) {b[x] = 1; find(x + 1);}
    b[x] = 0;
    for (i = s[x]; i < t[x]; i ++)
        a[i] -= num[x];
    find(x + 1);
}
    
int main()
{
int i;

	while (cin >> m >> n >> k)
    {
        if ((k == 0) && (m == 0) && (n == 0)) break;
        total = 0; max = 0;
        for (i = 0; i < n; i ++) a[i] = 0;
        for (i = 0; i < k; i ++) b[i] = 0;
        for (i = 0; i < k; i ++)
            cin >> s[i] >> t[i] >> num[i];
        find(0);
        cout << max << endl;
    }
    return 0;
}
