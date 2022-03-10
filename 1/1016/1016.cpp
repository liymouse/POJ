#include <stdio.h>
#include <string.h>

void change(char s1[] , char s2[])
{
int L , i , Long;
int a[10];

    L = strlen(s1); Long = 0;
    for (i = 0; i < 10; i ++) a[i] = 0;
    for (i = 0; i < L; i ++) a[s1[i] - '0'] ++;
    for (i = 0; i < 10; i ++)
        if (a[i] != 0)
        {
            if (a[i] > 9)
            {
                s2[Long ++] = a[i] / 10 + '0';
                s2[Long ++] = a[i] % 10 + '0';
            }
            else s2[Long++] = a[i] + '0';
            s2[Long++] = i + '0';
        }
    s2[Long] = 0;    
}    

int main()
{
char s[16][90] , s1[90] , s2[90];
int x , y , z , i , j , L , step , Long , bo;
int a[10];

    while (scanf("%s" , s[0]) == 1)
    {
        if (s[0][0] == '-') break;
        step = 0; x = 1; y = 0;
        while (step <= 15)
        {
            step++;
            change(s[y] , s[x]);
            //printf("%s\n" , s[x]);
            if (strcmp(s[y] , s[x]) == 0)
            {
                if (step == 1) printf("%s is self-inventorying\n" , s[0]);
                else printf("%s is self-inventorying after %d steps\n"  , s[0] , step-1);
                break;
            }    
            bo = 0;
            for (i = 0; i <= x-2; i ++)
                if ((strcmp(s[i] , s[x]) == 0) && (step <= 15))
                {printf("%s enters an inventory loop of length %d\n" , s[0] , step-i); bo = 1; break;}
            if (bo) break;
            y = x; x ++;
        }
        if (step == 16) printf("%s can not be classified after 15 iterations\n" , s[0]);
    }    
    return 0;
}

