#include <stdio.h>

const int N = 50003;
const int INF = 1 << 30;

typedef struct { int u , v , w; } edge;
edge E[N];

int n , d[N] , st , ed;

int Bellman_Ford(int s)
{
int VG = ed - st + 1;
bool over;

	for (int i = st; i <= ed; i ++) d[i] = -INF;
	d[s] = 0;
	for (int i = 1; i <= VG; i ++)
	{
		over = 1;
		// S(b) - S(a-1) >= c
		for (int j = 0; j < n; j ++)
		{
			if (d[E[j].u] != -INF && d[E[j].v] < d[E[j].u] + E[j].w)
			{
				d[E[j].v] = d[E[j].u] + E[j].w;
				over = 0;
			}
		}
		// S(j+1) - S(j) >= 0
		for (int j = st; j < ed; j ++)
		{
			if (d[j] != -INF && d[j] > d[j+1])
			{
				d[j+1] = d[j];
				over = 0;
			}
		}
		// S(j) - S(j-1) >= -1
		for (int j = ed; j > st; j --)
		{
			if (d[j] != -INF && d[j]-1 > d[j-1])
			{
				d[j-1] = d[j] - 1;
				over = 0;
			}
		}
		if (over) break;
	}
	return d[ed];
}

int main()
{
	int tn , a , b , c;

	while (scanf("%d" , &tn) == 1)
	{
		n = 0; st = N; ed = -1;
		for (int i = 0; i < tn; i ++)
		{
			scanf("%d %d %d" , &a , &b , &c);
			edge temp;
			temp.v = b + 1; temp.u = a; temp.w = c;
			E[n++] = temp;
			if (a < st) st = a;
			if (b + 1 > ed) ed = b + 1;
		}
		printf("%d\n" , Bellman_Ford(st));
	}
	return 0;
}
