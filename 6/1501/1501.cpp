#include <stdio.h>
#include <string.h>

char a[200][200];
int p[8][2] = {{-1 , -1} , {-1 , 0} , {-1 , 1} , {0 , -1} , {0 , 1} , {1 , -1} , {1 , 0} , {1 , 1}};

int main()
{
int n , i , j , L , k , find , x1 , y1 , x2 , y2 , t;
char s[201];

	scanf("%d" , &n);
	for (i = 0; i < n; i ++) scanf("%s" , a[i]);
	while (scanf("%s" , s) == 1)
	{
		if (s[0] == '0') break;
		L = strlen(s);
		if (L > n) {printf("Not found\n"); continue;}
		find = 0;
		for (i = 0; i < n; i ++)
		{
			for (j = 0; j < n; j ++)
				if (a[i][j] == s[0])
				{
					x1 = i; y1 = j;
					for (k = 0; k < 8; k ++)
					{
						x2 = x1 + p[k][0] * (L-1); y2 = y1 + p[k][1] * (L-1);
						if ((x2 >= 0) && (x2 < n) && (y2 >= 0) && (y2 < n))
						{
							find = 1; t = 0;
							while ((t < L) && (a[i + p[k][0] * t][j + p[k][1] * t] == s[t])) t ++;
							if (t == L) break; else find = 0;
						}
					}
					if (find) break;
				}
			if (find) break;
		}
		if (find) printf("%d,%d %d,%d\n" , x1+1 , y1+1 , x2+1 , y2+1);
		else printf("Not found\n");
	}
	return 0;
}