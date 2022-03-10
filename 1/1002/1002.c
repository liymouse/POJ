#include <stdio.h>
#include <string.h>
#define input "1002.in"

void qsort(long s , long t);

long a[100001];
char s[200];
long temp;
long n , size , bo;

int main()
{
long i , j , k , n1 , n2 , tot;

    scanf("%ld" , &n); size = 0;
    for (i = 0; i < n; i ++)
    {
        scanf("%s" , s);
        temp = 0;
        for (j = 0; j < strlen(s); j ++)
            if (((s[j] >= '0') && (s[j] <= '9')) ||
                ((s[j] >= 'A') && (s[j] <= 'Y')))
            {
                switch (s[j])
                {
                    case '0': case '1': case '2': case '3': 
                    case '4': case '5': case '6': case '7':
                    case '8': case '9':
                        k = s[j] - '0';
                    break;
                    case 'A': case 'B': case 'C':
                        k = 2;
                    break;
                    case 'D': case 'E': case 'F':
                        k = 3;
                    break;
                    case 'G': case 'H': case 'I':
                        k = 4;
                    break;
                    case 'J': case 'K': case 'L':
                        k = 5;
                    break;
                    case 'M': case 'N': case 'O':
                        k = 6;
                    break;
                    case 'P': case 'R': case 'S':
                        k = 7;
                    break;
                    case 'T': case 'U': case 'V':
                        k = 8;
                    break;
                    case 'W': case 'X': case 'Y':
                        k = 9;
                    break;
                }
                temp = temp * 10 + k;
            }
        a[size++] = temp;
    }
    qsort(0 , size-1); tot = 1; a[size] = -1;
    bo = 0;
    for (i = 0; i < size; i ++)
        if (a[i] != a[i+1])
        {
            if (tot > 1)
            {
                n1 = a[i] / 10000;
                n2 = a[i] % 10000;
                if (n1 < 10) printf("00");
                else if (n1 < 100) printf("0");
                printf("%ld-" , n1);
                if (n2 < 10) printf("000");
                else if (n2 < 100) printf("00");
                    else if (n2 < 1000) printf("0");
                printf("%ld " , n2);
                printf("%ld\n" , tot);
                tot = 1; bo = 1;
            }
        }
        else tot ++;
    if (bo == 0) printf("No duplicates.\n");
    return 0;
}

void qsort(long s , long t)
{
long i , j , x , y;

    i = s; j = t; x = a[(i + j) / 2];
    do
    {
        while (a[i] < x) i ++;
        while (a[j] > x) j --;
        if (i <= j)
        {
            y = a[i]; a[i] = a[j]; a[j] = y;
            i ++; j --;
        }    
    }
    while (i <= j);
    if (s < j) qsort(s , j);
    if (i < t) qsort(i , t);
}
