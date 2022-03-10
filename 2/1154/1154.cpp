#include <stdio.h>

int r , c , b[26] , max;
char a[20][20];
int k[4][2] = {{-1 , 0} , {0 , 1} , {1 , 0} , {0 , -1}};

void find(int x , int y , int tot)
{
int i , p , q;

	for (i = 0; i < 4; i ++)
	{
		p = x + k[i][0]; q = y + k[i][1];
		if ((p >= 0) && (p < r) && (q >= 0) && (q < c))
		{
			if (b[a[p][q] - 'A'] == 0) 
			{
				b[a[p][q] - 'A'] = 1;
				find(p , q , tot + 1);
				b[a[p][q] - 'A'] = 0;
			}
			else
				if (tot + 1 > max) max = tot + 1;
		}
	}
}

int main()
{
int i , j;
char s;

	scanf("%d %d\n" , &r , &c);
	for (i = 0; i < r; i ++)
	{
		for (j = 0; j < c; j ++)
			scanf("%c" , &a[i][j]);
		scanf("%c" , &s);
	}
	max = 0; for (i = 0; i < 26; i ++) b[i] = 0;
	b[a[0][0] - 'A'] = 1;
	find(0 , 0 , 0);
	printf("%d\n" , max);
	return 0;
}