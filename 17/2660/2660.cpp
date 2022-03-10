#include <stdio.h>
#include <string.h>

int main()
{
int m , n;
int i , j , tot;
int can[100];
struct {double x , y , z;}wei[100] , mu[100];
double a1 , b1 , c1 , a2 , b2 , c2;

	while (scanf("%d %d" , &m , &n) == 2)
	{
		if ((m == 0) && (n == 0)) break;
		for (i = 0; i < m; i ++) scanf("%lf %lf %lf" , &wei[i].x , &wei[i].y , &wei[i].z);
		for (i = 0; i < n; i ++) scanf("%lf %lf %lf" , &mu[i].x , &mu[i].y , &mu[i].z);
		memset(can , 0 , sizeof(can));
		for (i = 0; i < m; i ++)
			for (j = 0; j < n; j ++)
				if (can[j] == 0)
				{
					a1 = -mu[j].x; b1 = -mu[j].y; c1 = -mu[j].z;
					a2 = wei[i].x - mu[j].x; b2 = wei[i].y - mu[j].y; c2 = wei[i].z - mu[j].z;
					if (a1 * a2 + b1 * b2 + c1 * c2 <= 0) can[j] = 1;
				}
		tot = 0;
		for (i = 0; i < n; i ++) tot += can[i];
		printf("%d\n" , tot);
	}
	return 0;
}