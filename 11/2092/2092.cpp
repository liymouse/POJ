#include <stdio.h>
#include <algorithm>
using namespace std;

typedef struct
{
	int no , num;
}node;
node a[10001];

int cmp(node &a , node &b)
{
	if (a.num == b.num) return a.no < b.no;
	return a.num > b.num;
}

int main()
{
int n , m;
int i , j , x;

	while (scanf("%d %d" , &n , &m) == 2)
	{
		if (n == 0) break;
		for (i = 0; i <= 10000; i ++) {a[i].no = i; a[i].num = 0;}
		for (i = 0; i < n; i ++)
			for (j = 0; j < m; j ++)
			{
				scanf("%d" , &x);
				a[x].num ++;
			}
		sort(a , a + 10000 , cmp);
		i = 2;
		printf("%d " , a[1].no);
		while (a[i].num == a[i-1].num)
		{
			printf("%d " , a[i].no);
			i ++;
		}
		printf("\n");
	}
}
