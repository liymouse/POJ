#include <stdio.h>

int main()
{
char s[10];
float L;
int tot;
float totL;

    while (scanf("%s" , s) == 1)
    {
        if ((s[0] == '0') && (s[2] == '0') && (s[3] == '0')) break;
        L = 0;
        L = L + s[0] - '0';
        L = L + (s[2] - '0') * 0.1;
        L = L + (s[3] - '0') * 0.01;
        totL = 0; tot = 0;
        do
        {
            tot ++;
            totL = totL + 1/((tot + 1)*1.0);
        }while (!(totL - L >= 10e-6));
        printf("%d card(s)\n" , tot);
    }
    return 0;    
}    
