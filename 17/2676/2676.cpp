#include <stdio.h>
#include <string.h>

int hang[9][10] , lie[9][10] , ge[3][3][10];
int a[9][9] , done;

void find(int x , int y)
{
int i;

	if (x == 9) {done = 1; return;}
	if (a[x][y] > 0)
	{
		y ++; 
		if (y == 9) {x ++; y = 0;}
		find (x , y);
		if (done) return;
	}
	else
	{
		for (i = 1; i <= 9; i ++)
			if ((hang[x][i] == 0) && (lie[y][i] == 0) && (ge[x/3][y/3][i] == 0))
			{
				a[x][y] = i;
				hang[x][i] = 1; lie[y][i] = 1;
				ge[x/3][y/3][i] = 1;
				y ++;
				if (y == 9) {x ++; y = 0;}
				find(x , y);
				if (done) return;
				y --;
				if (y < 0) {y = 8; x --;}
				ge[x/3][y/3][i] = 0;
				hang[x][i] = 0; lie[y][i] = 0;
				a[x][y] = 0;
			}
	}
}

int main()
{
int i , j , n , h;
char s[10];

	scanf("%d" , &n);
	for (h = 0; h < n; h ++)
	{
		for (i = 0; i < 9; i ++)
		{
			scanf("%s" , &s);
			for (j = 0; j < 9; j ++) a[i][j] = s[j] - '0';
		}
		memset(hang , 0 , sizeof(hang));
		memset(lie , 0 , sizeof(lie));
		memset(ge , 0 , sizeof(ge));
		for (i = 0; i < 9; i ++)
			for (j = 0; j < 9; j ++) {hang[i][a[i][j]] = 1; lie[i][a[j][i]] = 1; ge[i/3][j/3][a[i][j]] = 1;}
		done = 0;
		find(0 , 0);
		for (i = 0; i < 9; i ++)
		{
			for (j = 0; j < 9; j ++) printf("%d" , a[i][j]);
			printf("\n");
		}
	}
	return 0;
}