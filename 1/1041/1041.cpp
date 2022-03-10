//输入一个无向图，先判断是否存在欧拉回路，若有求出一条欧拉回路
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

struct stack{int top , node[2010];} f; //顶点的堆栈
int a[45][45]; //图的邻接矩阵
int st[45][45][100];
int nm[45][45];
int n , m , tot , from , to;
struct kk{int x , y , z;} data[2000];
int boo[2000];

bool cmp(kk &x , kk &y)
{
	return x.z < y.z;
}

void dfs(int x)
{
int i , j , max , k , t , have;

	f.top ++; f.node[f.top] = x;
	max = 0; have = 0;
	for (i = 1; i <= n; i ++)
//		if (a[i][x] > 0) {a[i][x] --; a[x][i] --; dfs(i); break;}
		if (a[i][x] > 0)
		{
			for (j = 1; j <= nm[i][x]; j ++)
				if ((boo[st[i][x][j]] == 0) && (st[i][x][j] > max))
				{
					k = i; t = j; max = st[i][x][j]; break;
				}
			have = 1;
		}
	if (have) {a[x][k] --; a[k][x] --; boo[st[k][x][t]] = 1; dfs(k);}
}

void printstreet(int x , int y)
{
int i;

	i = 1;
	while (i <= nm[x][y])
	{
		if (st[x][y][i] > 0)
		{
			printf("%d" , st[x][y][i]);
			st[x][y][i] = 0; st[y][x][i] = 0;
			break;
		}
		i ++;
	}
}

void Euler(int x)
{
int i , b;

	f.top = 0; f.node[f.top] = x;
	while (f.top >= 0)
	{
		b = 0;
		for (i = 1; i <= n; i ++) if (a[f.node[f.top]][i] > 0) {b = 1; break;}
		if (b == 0)
		{
			//printf("%d " , f.node[f.top]);
			if (tot == 0) {tot = 1; from = f.node[f.top];}
			else
			{
				if (tot > 1) printf(" ");
				to = f.node[f.top];
				printstreet(from , to);
				from = to;
				tot = 2;
			}
			f.top --;
		}
		else {f.top --; dfs(f.node[f.top+1]);}
	}
}

int main()
{
int s , k , t , num , i , j , start , street , p , q;

	while (scanf("%d %d" , &data[0].x , &data[0].y) == 2)
	{
		if (data[0].x == 0) break;
		k = 0; scanf("%d" , &data[0].z);
		while (1)
		{
			k ++; scanf("%d %d" , &data[k].x , &data[k].y);
			if (data[k].x == 0) break;
			scanf("%d" , &data[k].z);
		}
		sort(data , data + k , cmp);
		memset(a , 0 , sizeof(a));
		memset(st , 0 , sizeof(st));
		memset(nm , 0 , sizeof(nm));
		memset(boo , 0 , sizeof(boo));
		n = 1; m = 1; tot = 0;
		start = data[0].x < data[0].y ? data[0].x : data[0].y;
		for (i = 0; i < k; i ++)
		{
			s = data[i].x; t = data[i].y; street = data[i].z;
			if (s > n) n = s;
			if (t > n) n = t;
			if (street > m) m = street;
			a[s][t] ++; a[t][s] ++;
			nm[s][t] ++; nm[t][s] ++;
			st[s][t][nm[s][t]] = street;
			st[t][s][nm[s][t]] = street;
		}
		//判断是否存在欧拉回路
		s = 0; p = 0;
		for (i = 1; i <= n; i ++)
		{
			num = 0;
			for (j = 1; j <= n; j ++)
				num += a[i][j];
			if (num % 2 == 1) {if (!p) p = i; else q = i; s ++;}
			//if (num % 2 == 1) {start = i; s ++;}
		}
		if ((s == 0) || ((s == 2) && (p == start || q == start))) Euler(start);
		else printf("Round trip does not exist.");
		printf("\n");
	}
	return 0;
}