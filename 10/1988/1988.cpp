#include <stdio.h>

int father[30010];
int below[30010];
int num[30010];

int find(int x)
{
int t;
	if (father[x] == x) return x;
	t = find(father[x]);
	below[x] += below[father[x]];
	father[x] = t;
	return t;
}

int main()
{
int q , x , y , i;
char s[3];

	//freopen("input.txt" , "r" , stdin);
	for (i = 1; i <= 30000; i ++) {father[i] = i; below[i] = 0; num[i] = 1;}
	scanf("%d" , &q);
	for (i = 0; i < q; i ++)
	{
		scanf("%s" , s);
		if (s[0] == 'M')
		{
			scanf("%d %d" , &x , &y);
			x = find(x); y = find(y);
			father[x] = y; 
			below[x] += num[y];
			num[y] += num[x];
		}
		else
		{
			scanf("%d" , &x);
			find(x);
			printf("%d\n" , below[x]);
		}
	}
	return 0;
}