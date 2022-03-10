#include <stdio.h>
#include <math.h>

int main()
{
    char s[2010];
    int ca = 1;
    while (scanf("%s" , s) == 1)
    {
        if (s[0] == '-') break;
        int x = 0 , res = 0;
        for (int i = 0; s[i] != 0; i ++)
        {
            if (s[i] == '{') x ++;
            else if (x > 0) x --;
            else {x ++; res ++;}
        }
        res += x/2;
        printf("%d. %d\n" , ca++ , res);
    }
    return 0;
}
