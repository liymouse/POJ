#include <stdio.h>
#include <string.h>

int main()
{
char s[1010];
int a[1000];
int t , h;
int L , k;
int i , j;
long tot;

    scanf("%d\n" , &t);
    for (h = 1; h <= t; h ++)
    {
        gets(s);
        printf("Scenario #%d:\n" , h);
        L = strlen(s);
        j = 0;
        for (i = L-1; i >= 0; i --)
        {
            if (j % 3 == 0) a[i] = 9;
            else if (j % 3 == 1) a[i] = 3;
            else if (j % 3 == 2) a[i] = 7;
            j ++;
        }
        tot = 0;
        for (i = 0; i < L; i ++)
            if (s[i] != '?')
                tot += a[i] * (s[i]-'0');
            else k = i;
        for (i = 0; i < 10; i ++)
            if ((tot + i * a[k]) % 10 == 0) {s[k] = '0' + i; break;}
        printf("%s\n\n" , s);
    }
    return 0;
}
