#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

typedef struct
{
	int key;
	int w;
}node;

typedef __int64 I64;

vector<vector<node>> a , b;

int dist[1000010];
bool inque[1000010];
int q , p;

I64 spfa(vector<vector<node>> &a)
{
int i , k , x;
queue<int> que;
I64 res;

	for (i = 0; i < p; i ++) {dist[i] = -1; inque[i] = false;}
	dist[0] = 0;
	que.push(0);
	inque[0] = true;
	while(!que.empty())
	{
		k = que.front();
		que.pop();
		inque[k] = false;
		for (i = 0; i < a[k].size(); i ++)
		{
			x = a[k][i].key;
			if (dist[x] == -1 || dist[x] > dist[k] + a[k][i].w)
			{
				dist[x] = dist[k] + a[k][i].w;
				if (!inque[x])
				{
					inque[x] = true;
					que.push(x);
				}
			}
		}
	}
	res = 0;
	for (i = 0; i < p; i ++)
		res += dist[i];
	return res;
}

int main()
{
int cas;
int i , x , y , z;
node no;

	scanf("%d" , &cas);
	while (cas --)
	{
		scanf("%d %d" , &p , &q);
		a.clear(); b.clear();
		a.resize(p);
		b.resize(p);
		for (i = 0; i < q; i ++)
		{
			scanf("%d %d %d" , &x , &y , &z);
			if (x == 1)
			{
				no.key = y-1;
				no.w = z;
				a[0].push_back(no);
			}
			else if (y == 1)
			{
				no.key = x-1;
				no.w = z;
				b[0].push_back(no);
			}
			else
			{
				no.key = y-1;
				no.w = z;
				a[x-1].push_back(no);
				no.key = x-1;
				b[y-1].push_back(no);
			}
		}
		printf("%I64d\n" , spfa(a) + spfa(b));
	}
	return 0;
}
