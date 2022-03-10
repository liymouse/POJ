#include <stdio.h>
#include <string.h>

int main()
{
int qf[8][2] = {{-1 , -1} , {-1 , 0} , {-1 , 1} , {0 , -1} , {0 , 1} , {1 , -1} , {1 , 0} , {1 , 1}};
int kf[8][2] = {{-1 , -2} , {-2 , -1} , {-2 , 1} , {-1 , 2} , {1 , 2} , {2 , 1} , {2 , -1} , {1 , -2}};
char a[1001][1001];
int n , m , i , j , nk , nq , np , s , t;
int tot , h;
struct kk{int x , y;}k[100] , q[100] , p[100];
	
	h = 0;
	while (scanf("%d %d" , &n , &m) == 2)
	{
		if ((n == 0) && (m == 0)) break;
		memset(a , 0 , sizeof(a));
		tot = 0;
		scanf("%d" , &nq);
		for (i = 0; i < nq; i ++) {scanf("%d %d" , &q[i].x , &q[i].y); a[q[i].x][q[i].y] = 1; tot ++;}
		scanf("%d" , &nk);
		for (i = 0; i < nk; i ++) {scanf("%d %d" , &k[i].x , &k[i].y); a[k[i].x][k[i].y] = 2; tot ++;}
		scanf("%d" , &np);
		for (i = 0; i < np; i ++) {scanf("%d %d" , &p[i].x , &p[i].y); a[p[i].x][p[i].y] = 3; tot ++;}
		for (i = 0; i < nq; i ++)
		{
			for (j = 0; j < 8; j ++)
			{
				s = q[i].x + qf[j][0]; t = q[i].y + qf[j][1];
				while ((s > 0) && (s <= n) && (t > 0) && (t <= m) && (a[s][t] != 2) && (a[s][t] != 3))
				{
					if (a[s][t] == 0) {tot ++; a[s][t] = 4;}
					s += qf[j][0]; t += qf[j][1];
				}
			}
		}
		for (i = 0; i < nk; i ++)
		{
			for (j = 0; j < 8; j ++)
			{
				s = k[i].x + kf[j][0]; t = k[i].y + kf[j][1];
				if ((s > 0) && (s <= n) && (t > 0) && (t <= m) && (a[s][t] == 0)) {tot ++; a[s][t] = 4;}
			}
		}
		tot = n * m - tot; h ++;
		printf("Board %d has %d safe squares.\n" , h , tot);
	}
	return 0;
}