#include <stdio.h>
#include <string.h>

char s1[20] , s2[20];
char s[500000][20];
char a[250000][20] , b[250000][20];
long no[500000];
long father[500000];
long n;

void qu(long ss , long tt)
{
long i , j;
char x[20] , y[20];
    
    i = ss; j = tt; strcpy(x , s[(i+j)/2]);
    while (i <= j)
    {
        while (strcmp(s[i] , x) < 0) i ++;
        while (strcmp(s[j] , x) > 0) j --;
        if (i <= j)
        {
            strcpy(y , s[i]); strcpy(s[i] , s[j]); strcpy(s[j] , y);
            i ++; j --;
        }
    }
    if (i < tt) qu(i , tt);
    if (ss < j) qu(ss , j);
}

long getfather(long x)
{
long f;

	if (father[x] == x) return x;
	else
	{
		f = getfather(father[x]);
		father[x] = f;
		return f;
	}
}

long find(char st[])
{
long x , y , z;

    x = 0; y = n - 1;
    while (1)
    {
        z = (x + y) / 2;
        if (x >= y) break;
        if (strcmp(st , s[z]) < 0) y = z - 1;
        else if (strcmp(st , s[z]) > 0) x = z + 1;
        else break;
    }
    return no[z];
}

int main()
{
long t , tot , i , x , y , p , q , bo;

    n = 0;
    while (scanf("%s %s" , s1 , s2) == 2)
    {
        //if (s1[0] == 0) break;
        strcpy(a[n/2] , s1);
        strcpy(b[n/2] , s2);
        strcpy(s[n++] , s1);
        strcpy(s[n++] , s2);
    }
    qu(0 , n-1); t = 1; no[0] = 1;
    for (i = 1; i < n; i ++) 
        if (strcmp(s[i-1] , s[i]) == 0) no[i] = t;
        else {t ++; no[i] = t;}
    if (t == 1) {printf("Possible\n"); return 0;}
    for (i = 0; i <= 250000; i ++) father[i] = i;
    for (i = 0; i < n / 2; i ++)
    {
        x = find(a[i]);
        y = find(b[i]);
        p = getfather(x); q = getfather(y);
        father[p] = q;
    }
    bo = 0;
    for (i = 2; i <= t; i ++)
    {
        x = getfather(i-1);
        y = getfather(i);
        if (x != y) {bo = 1; break;}
    }
    if (bo == 1) printf("Impossible\n");
    else
    {
        tot = 0; t = 1;
        for (i = 1; i < n; i ++)
            if (strcmp(s[i-1] , s[i]) == 0) t ++;
            else
            {
                if (t % 2 == 1) tot ++;
                t = 1;
                if (tot > 2) break;
            }
        if (t % 2 == 1) tot ++;
        if ((tot == 0) || (tot == 2)) printf("Possible\n");
        else printf("Impossible\n");
    }
    return 0;
}
