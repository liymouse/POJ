#include <iostream.h>
#include <string.h>

int main()
{
char s[70];
int a[70] , b[70];
int n , i , j , bo , x , y , done;

    while (cin >> s)
    {
        n = strlen(s);
        for (i = 0; i < n; i ++) a[i] = s[n-1-i] - '0';
        for (i = 0; i < n; i ++) b[i] = a[i];
        b[n] = 0; done = 1;
		for (i = 1; i < n; i ++)
        {
            for (j = 0; j < n; j ++)
            {
                b[j] += a[j];
                if (b[j] > 9)
                {
                    b[j + 1] += b[j] / 10;
                    b[j] %= 10;
                }
            }
            if (b[n] > 0) {done = 0; break;}
            bo = 0;
            for (j = 0; j < n; j ++)
                if (b[j] == a[0])
                {
                    x = 0; y = j;
                    while ((x < n) && (a[x] == b[y]))
                    {
                        x ++; y ++;
                        if (y == n) y = 0;
                    }
                    if (x == n) {bo = 1; break;}
                }
            if (bo == 0) {done = 0; break;}
        }
        if (done) cout << s << " is cyclic" << endl;
        else cout << s << " is not cyclic" << endl;
    }
    return 0;
}        
