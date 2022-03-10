#include <stdio.h>
#include <string.h>

int main()
{
char ss[100] , c;
int a[26] , b[51] , i , j , max;

    for (i = 0; i < 26; i ++) a[i] = 0;
    for (i = 0; i < 4; i ++)
    {
        gets(ss);
        for (j = 0; j < strlen(ss); j ++)
            if ((ss[j] >= 'A') && (ss[j] <= 'Z')) a[ss[j]-'A']++;
    }
    while (1)
    {
        max = 0;
        for (i = 0; i < 51; i ++) b[i] = 0;
        for (i = 0; i < 26; i ++)
            if (a[i] > max) max = a[i];
        if (max == 0) break;
        for (i = 0; i < 26; i ++)
            if (a[i] == max) {b[2 * i] = 1; a[i] --;}
        for (i = 0; i < 51; i ++) 
            if (b[i] == 0) printf(" ");
            else printf("*");
        printf("\n");
    }
    for (i = 0; i < 25; i ++)
        printf("%c " , 'A' + i);
    printf("Z");
    return 0;
}    
