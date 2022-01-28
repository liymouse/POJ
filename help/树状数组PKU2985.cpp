//PKU 2985
//2 operations : combine 2 groups / find the k-largest group's size
//Ê÷×´Êý×é
#include <stdio.h>
#include <string.h>

int father[200001];
int num[200001];
int tree[1 + 1 << 18];
int f[19];
int max;

int getfather(int x)
{
	if (father[x] != x) father[x] = getfather(father[x]);
	return father[x];
}

int lowbit(int x)
{
	return x & (x ^ (x - 1));
}

void change(int k , int delta)
{
	while (k <= f[max])
	{
		tree[k] += delta;
		k += lowbit(k);
	}
}

int main()
{
int m , n;
int i , j , x , y , k;
int p , q;

	f[0] = 1;
	for (i = 1; i < 19; i ++) f[i] = f[i-1] * 2;
	scanf("%d %d" , &n , &m);
	for (j = 0; j < 19; j ++) if (n < f[j]) {max = j; break;}
	for (i = 1; i <= n; i ++) {father[i] = i; num[i] = 1;}
	memset(tree , 0 , sizeof(tree));
	change(1 , n);
	for (i = 0; i < m; i ++)
	{
		scanf("%d" , &k);
		if (k)
		{
			scanf("%d" , &x);
			x = n - x + 1;
			y = f[max]; j = f[max-1];
			while (j)
			{
				if (tree[y - j] >= x) y -= j;
				else x -= tree[y - j];
				j /= 2;
			}
			printf("%d\n" , y);
		}
		else
		{
			scanf("%d %d" , &x , &y);
			p = getfather(x);
			q = getfather(y);
			if (p != q)
			{
				father[p] = q;
				change(num[p] , -1);
				change(num[q] , -1);
				num[q] += num[p];
				change(num[q] , 1);
				n --;
			}
		}
	}
	return 0;
}