#include <stdio.h>
#include <string.h>

int d(int x1 , int y1 , int x2 , int y2)
{
	return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)*3;
}

int main()
{
int num[26] , n , L , b[26] , no;
int i , j , k , m;
int x[3] , y[3] , s , t;
char st[80];

	while (scanf("%d" , &n) == 1)
	{
		if (n == 0) break;
		scanf("%s" , st);
		memset(num , 0 , sizeof(num));
		memset(b , 0 , sizeof(b));
		no = 0;
		L = n * (n + 1) / 2;
		for (i = 0; i < L; i ++) num[st[i] - 'a'] ++;
		for (i = 0; i < 26; i ++)
			if (num[i] == 3)
			{
				m = 0;
				for (j = 0; j < L; j ++) 
					if (st[j] == i + 'a')
					{
						x[m] = 1; k = j + 1;
						while (k > x[m]) {k -= x[m]; x[m] ++;}
						y[m] = k;
						m ++;
					}
				for (j = 0; j < 3; j ++)
				{
					t = (n - x[j] + 1);
					if (x[j] % 2 == 0) s = 2 * (y[j] - x[j]/2) - 1;
					else s = 2 * (y[j] - x[j]/2 - 1);
					x[j] = s; y[j] = t;
				}
				if ((d(x[0] , y[0] , x[1] , y[1]) == d(x[1] , y[1] , x[2] , y[2])) && 
					(d(x[1] , y[1] , x[2] , y[2]) == d(x[2] , y[2] , x[0] , y[0]))) 
				{b[i] = 1; no = 1;}
			}
		if (no == 0) printf("LOOOOOOOOSER!");
		else for (i = 0; i < 26; i ++) if (b[i]) printf("%c" , 'a' + i);
		printf("\n");
	}
	return 0;
}