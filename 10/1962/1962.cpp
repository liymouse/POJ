#include <stdio.h>
#include <math.h>

int father[20001];
long Lon[20001];

int getfather(int x)
{
int f;

	if (father[x] == x) return x;
	else
	{
		f = getfather(father[x]);
		Lon[x] += Lon[father[x]];
		father[x] = f;
		return f;
	}
}


int main()
{
int t , h , n , m , a , b , k;
int i;
char s[10];

	//freopen("input.txt" , "r" , stdin);
	scanf("%d" , &t);
	for (h = 0; h < t; h ++)
	{
		scanf("%d" , &n);
		for (i = 1; i <= n; i ++) {father[i] = i; Lon[i] = 0;}
		while (scanf("%s"  , s) == 1)
		{
			if (s[0] == 'O') break;
			else if (s[0] == 'E')
			{
				scanf("%d" , &m);
				getfather(m);
				printf("%ld\n" , Lon[m]);
			}
			else
			{
				scanf("%d %d" , &a , &b);
				father[a] = b;
				Lon[a] += (abs(a - b)) % 1000;
			}
		}
	}
	return 0;
}
