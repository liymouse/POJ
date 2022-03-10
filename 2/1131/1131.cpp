#include <stdio.h>
#include <string.h>

int main()
{
char st[50];
int result[1000] , a[1000] , b[1000] , *s , *t , *r , p[3] = {5 , 2 , 1};
int i , j , k , h , num;
int Ls , La , Lb;

	while (scanf("%s" , st) == 1)
	{
		printf("%s [8] = " , st);
		if (st[0] == '1') printf("1 [10]\n");
		else if ((st[0] == '0') && (st[1] == 0)) printf("0 [10]\n");
		else
		{
			Ls = strlen(st);
			memset(result , 0 , sizeof(result));
			memset(a , 0 , sizeof(a));
			memset(b , 0 , sizeof(b));
			a[0] = 1; num = 0; La = 1;
			s = a; t = b;
			for (h = 2; h < Ls; h ++)
			{
				num += 3; k = st[h] - '0';
				for (i = 0; i < num; i ++) t[i] = 0;
				for (i = 0; i < La; i ++)
					for (j = 0; j < 3; j ++)
					{
						t[i + j] += s[i] * p[j];
						if (t[i + j] > 9)
						{
							t[i + j + 1] += t[i + j] / 10;
							t[i + j] %= 10;
						}
					}
				if (t[La + 2] == 0) Lb = La + 2; else Lb = La + 3;
				for (i = num - Lb; i < num; i ++)
					result[i] += k * t[num - i - 1];
				for (i = num-1; i > 0; i --)
					if (result[i] > 9) 
					{
						result[i-1] += result[i] / 10;
						result[i] %= 10;
					}
				r = s; s = t; t = r; La = Lb;
			}
			printf("0.");
			i = num - 1; while (result[i] == 0) i --;
			num = i + 1;
			for (i = 0; i < num; i ++) printf("%d" , result[i]);
			printf(" [10]\n");
		}
	}
	return 0;
}