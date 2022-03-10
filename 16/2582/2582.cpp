#include <stdio.h>
#include <string.h>

struct {int x , y , d;} bo[10] , f[30];
int main()
{
char s[1000];
//int p[9][2] = {{-1 , -1} , {-1 , 0} , {-1 , 1} , {0 , -1} , {0 , 0} , {0 , 1} , {1 , -1} , {1 , 0} , {1 , 1}};
int p[5][2] = {{-1 , 0} , {0 , -1} , {0 , 0} , {1 , 0} , {0 , 1}};
int L , w , d;
int i , j , k , n , m , x , y , done;
int strL;
int b[30] , tot;

	while (scanf("%s" , s) == 1)
	{
		if (s[0] == 'E') return 0;
		scanf("%d %d %d\n" , &L , &w , &d);
		memset(bo , 0 , sizeof(bo));
		memset(f , 0 , sizeof(f));
		memset(b , 0 , sizeof(b));
		tot = 0;
		gets(s);
		i = 0; n = 0; strL = strlen(s);
		while (i < strL)
		{
			while ((i < strL) && (s[i] >= '0') && (s[i] <= '9')) bo[n].x = bo[n].x * 10 + s[i++] - '0';
			i ++;
			while ((i < strL) && (s[i] >= '0') && (s[i] <= '9')) bo[n].y = bo[n].y * 10 + s[i++] - '0';
			i ++;
			while ((i < strL) && (s[i] >= '0') && (s[i] <= '9')) bo[n].d = bo[n].d * 10 + s[i++] - '0';
			if (bo[n].d > d) bo[n].d = d;
			n ++; i ++;
		}
		gets(s);
		i = 0; m = 0; strL = strlen(s);
		while (i < strL)
		{
			while ((i < strL) && (s[i] >= '0') && (s[i] <= '9')) f[m].x = f[m].x * 10 + s[i++] - '0';
			i ++;
			while ((i < strL) && (s[i] >= '0') && (s[i] <= '9')) f[m].y = f[m].y * 10 + s[i++] - '0';
			i ++;
			while ((i < strL) && (s[i] >= '0') && (s[i] <= '9')) f[m].d = f[m].d * 10 + s[i++] - '0';
			m ++; i ++;
		}
		for (i = 0; i < n; i ++)
		{
			for (j = 0; j < m; j ++)
			{
				if ((b[j] == 0) && (f[j].d == bo[i].d))
				{
					done = 0;
					for (k = 0; k < 5; k ++)
					{
						x = bo[i].x + p[k][0];
						y = bo[i].y + p[k][1];
						if ((f[j].x == x) && (f[j].y == y)) {done = 1; break;}
					}
					if (done == 1) {b[j] = 1; tot ++;}
				}
				if ((b[j] == 0) && (f[j].x == bo[i].x) && (f[j].y == bo[i].y) && ((f[j].d == bo[i].d - 1) || (f[j].d == bo[i].d + 1)))
				{
					b[j] = 1; tot ++;
				}
			}
		}
		if (tot == 0) printf("None of dem fish blowed up!\n");
		else printf("AIEE, I got %d fish, me!\n" , tot);
		scanf("%s" , s);
	}
	return 0;
}
