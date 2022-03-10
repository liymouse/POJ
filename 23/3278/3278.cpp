#include <stdio.h>
#include <queue>
using namespace std;

char a[200010] = {0};
typedef struct
{
	int x , num;
}node;

int main()
{
int n , k;
int res;
queue<node> que;
node b , c;

	scanf("%d %d" , &n , &k);
	b.x = n; b.num = 0;
	a[n] = 1;
	que.push(b);
	while (!que.empty())
	{
		b = que.front();
		if (b.x == k) {c = b; break;}
		que.pop();
		if (b.x - 1 >= 0 && a[b.x-1] == 0)
		{
			c.x = b.x - 1;
			c.num = b.num + 1;
			if (c.x == k) break;
			que.push(c);
			a[c.x] = 1;
		}
		if (b.x + 1 <= k && a[b.x + 1] == 0)
		{
			c.x = b.x + 1;
			c.num = b.num + 1;
			if (c.x == k) break;
			que.push(c);
			a[c.x] = 1;
		}
		if (b.x < k && a[b.x * 2] == 0)
		{
			c.x = b.x * 2;
			c.num = b.num + 1;
			if (c.x == k) break;
			que.push(c);
			a[c.x] = 1;
		}
	}
	printf("%d\n" , c.num);
	return 0;
}
