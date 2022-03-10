#include <iostream.h>
#include <string.h>

long gc(long a , long b)
{
long p , q , x;

    if (a > b) {p = a; q = b;} else {p = b; q = a;}
    while (1)
    {
        if (p % q == 0) return q;
        x = q; q = p % q; p = x;
    }
}

int main()
{
char s[510][30];
long tot1 = 0, tot2 = 0 , x;
char str[3000];
int i , j , k , up = 0 , b , p;
    
    while (cin >> str)
    {
        //gets(str);
        //if (str[0] == 0) break;
        i = 0;
        strlwr(str);
        k = 0;
        while (str[i] != 0)
        {
            while (((str[i] > 'z') || (str[i] < 'a')) && (str[i] != 0)) i ++;
            if (str[i] == 0) break;
            k = 0;
            while ((str[i] >= 'a') && (str[i] <= 'z'))
            {
                s[up][k ++] = str[i];
                i ++;
            }
            s[up][k] = 0;
            if (strcmp("bullshit" , s[up]) == 0)
            {
                tot1 += up; tot2 ++;
                up = 0;
            }
            else
            {
                b = 0;
                for (j = 0; j < up; j ++)
                    if (strcmp(s[j] , s[up]) == 0) {b = 1; break;}
                if (b == 0) up ++;
            }
        }
    }
    if (tot2 == 0) cout << 0 << endl;
    else 
    {
        x = gc(tot1 , tot2);
        tot1 = tot1 / x; tot2 = tot2 / x;
        if (tot2 > 1) cout << tot1 << " / " << tot2 << endl;
        else cout << tot1 << endl;
    }
    return 0;
}
