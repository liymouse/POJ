#include <stdio.h>
#include <string.h>

int main()
{
int cas , ca;
int f[100][100];
int p[100][100];
int a[100] , b[100];
char button[100] , cha[100];
int n , L , i , j , k , s , t , min , h;

	scanf("%d" , &cas);
	for (ca = 1; ca <= cas; ca ++)
	{
		scanf("%d %d" , &n , &L);
		scanf("%s" , button);
		scanf("%s" , cha);
		for (i = 1; i <= L; i ++)
		{
			scanf("%d" , &a[i]);
		}
		memset(f , 0 , sizeof(f));
		memset(p , 0 , sizeof(p));
		f[1][1] = a[1];
		for (i = 2; i <= L; i ++)
			f[1][i] = f[1][i-1] + i * a[i];
		for (j = 2; j <= n; j ++)
			for (i = j; i <= L; i ++)
			{
				min = 2000000000;
				for (k = j-1; k < i; k ++)
				{
					s = f[j-1][k];
					for (h = 1; h <= i - k; h ++) s += h * a[k + h];
					if (s < min)
					{
						min = s; 
						t = k;
					}
				}
				f[j][i] = min;
				p[j][i] = t;
			}
		memset(b , 0 , sizeof(b));
		i = L; j = n;
		while (j > 0)
		{
			i = p[j][i];
			j --;
			b[i] = 1;
		}
		printf("Keypad #%d:\n" , ca);
		j = 1;
		printf("%c: " , button[0]);
		for (i = 1; i <= L; i ++)
		{
			printf("%c" , cha[i-1]);
			if (b[i] == 1)
			{
				printf("\n");
				printf("%c: " , button[j]);
				j ++;
			}
		}
		printf("\n\n");
	}
	return 0;
}
