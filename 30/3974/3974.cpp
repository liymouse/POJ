#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;

char str[1000010];
char s[2000100];
int p[2000100];
int main()
{
    int ca = 1;
    while (scanf("%s" , str) == 1)
    {
        if (str[0] == 'E') break;
        int maxL = 0;
        int len = strlen(str);
        s[0] = '^';
        for (int i = 0; i < len; i ++)
        {
            s[i*2+1] = '#';
            s[i*2+2] = str[i];
        }
        s[len*2+1] = '#';
        s[len*2+2] = 0;
        len = len*2 + 2;
        p[0] = 0;
        int id = 0;
        int mx = 0;
        for (int i = 1; i < len; i ++)
        {
            p[i] = 1;
            if (i < mx) p[i] = min(mx - i , p[2*id-i]);
            while (s[i-p[i]] == s[i+p[i]]) p[i] ++;
            if (p[i] + i > mx)
            {
                id = i;
                mx = p[i] + i;
            }
            maxL = max(maxL , p[i]);
        }
        printf("Case %d: %d\n" , ca ++ , maxL-1);
    }
    return 0;
}
