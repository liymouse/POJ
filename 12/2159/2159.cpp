#include <stdio.h>
#include <string.h>

int main()
{
char s1[110] , s2[110] , s3[110];
int a[26] = {0} , b[26] = {0} , c[26] , d[26];
int L , bo , t , k;
int i , j , h;

    gets(s1); gets(s2);
    L = strlen(s1);
    for (i = 0; i < L; i ++) {a[s1[i] - 'A'] ++; b[s2[i] - 'A'] ++;}
    for (i = 0; i < 26; i ++)
        for (j = 1; j < 26 - i; j ++)
        {
            if (a[j-1] > a[j]) {t = a[j-1]; a[j-1] = a[j]; a[j] = t;}
            if (b[j-1] > b[j]) {t = b[j-1]; b[j-1] = b[j]; b[j] = t;}
        }
    bo = 0;
    for (i = 0; i < 26; i ++)
        if (a[i] != b[i]) {bo = 1; break;}
    if (bo == 0) printf("YES\n"); else printf("NO\n");
    getchar(); getchar();
    return 0;
}

