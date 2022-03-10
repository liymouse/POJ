#include <stdio.h>

void deal(int *r , int dot , int n , int m);

int main()
{
int r[6] , dot;
char c;
int i , j , n , m , k;
char s[20];

    while (scanf("%s %d" , s , &n) == 2)
    {
		for (i = 0; i < 6; i ++) r[i] = 0;
		j = -1;
		for (i = 0; i < 6; i ++)
			if ((s[i] >= '0') && (s[i] <= '9')) r[++j] = s[i] - '0';
			else if (s[i] == '.') dot = 5 - j - 1;
		k = 4;
		while ((r[k] == 0) && (k >= 5 - dot)) k --;
  		dot -= 4 - k;  m = 0;
		if (k != 4) for (i = 5; i > k; i --) r[i] = 0;
		while (r[m] == 0) m ++;
		if (m != 0) for (i = m; i < 5; i ++) r[i-m] = r[i];
		m = k - m + 1;
        deal(r , dot , n , m);
    }    
    return 0;
}    

void deal(int r[] , int dot , int n , int m)
{
int result[5][150] = {0};
int size[5] , sizea;
int a[2000] = {0};
int i , j , k;

    for (i = 0; i < m/2; i ++)
        {j = r[m-i-1]; r[m-i-1] = r[i]; r[i] = j;}
    for (i = 0; i < m; i ++)
        a[i] = r[i];
    sizea = m - 1;
    for (k = 1; k < n; k ++)
    {
        for (i = 0; i < m; i ++)
        {
            for (j = 0; j <= sizea; j ++)
                result[i][j] = a[j] * r[i];
            size[i] = sizea;
            for (j = 0; j <= size[i]; j ++)
                if (result[i][j] >= 10)
                {
                    result[i][j+1] += result[i][j] / 10;
                    result[i][j] %= 10;
                }    
            if (result[i][size[i]+1] > 0) size[i] ++;
		}
		for (i = 0; i <= sizea; i ++)
			a[i] = 0;
		for (i = 0; i < m; i ++)
		{
			for (j = i; j <= size[i]+i; j ++)
			{
				a[j] += result[i][j-i];
			}
		}
		sizea = size[m-1] + m-1;
		for (i = 0; i <= sizea; i ++)
            if (a[i] >= 10)
            {
                a[i+1] += a[i] / 10;
                a[i] %= 10;
            }
        if (a[sizea+1] > 0) sizea ++;
    }
    dot *= n;
    if (dot >= sizea + 1) printf(".");
    for (i = 1; i < dot - sizea; i ++)
        printf("0");
    for (i = sizea; i >= 0; i --)
    {
        printf("%d" , a[i]);
		if ((dot != 0) && (i == dot)) printf(".");
    }    
    printf("\n");
}    
