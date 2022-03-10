#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;

typedef struct
{
	int num;
	char name[105];
	char pos[3];
	int time;
}player;

player a[30];
int b[30];

int deal(char te[])
{
int res , i , x , y , L , k;
char s[1000];

	L = strlen(te); k = 0;
	for (i = 0; i < L; i ++)
		if ((te[i] >= '0') && (te[i] <= '9')) s[k ++] = te[i];
	s[k] = 0;
	L = k;
	res = 0;
	for (i = 0; i < L; i += 8)
	{
		x = (s[i]-'0') * 1000 + (s[i+1] - '0') * 100 + (s[i+2] - '0') * 10 + s[i+3] - '0';
		y = (s[i+4]-'0') * 1000 + (s[i+5] - '0') * 100 + (s[i+6] - '0') * 10 + s[i+7] - '0';
		res += y - x + 1;
	}
	return res;
}

int cmp(player x , player y)
{
	return x.num < y.num;
}

int main()
{
int i , n , G , D , M , S , t , j , max , k , maxn;
char s[1000];
int order[11];

	n = 22;
	while (scanf("%d" , &i) == 1)
	{
		if (i == 0) break;
		a[0].num = i;
		scanf("%s %s" , a[0].name , a[0].pos);
		gets(s);
		a[0].time = deal(s);
		for (i = 1; i < n; i ++)
		{
			scanf("%d %s %s" , &a[i].num , a[i].name , a[i].pos);
			gets(s);
			a[i].time = deal(s);
		}
		scanf("%d-%d-%d" , &D , &M , &S);
		sort(a , a + n , cmp);
		memset(b , 0 , sizeof(b));
		t = 0;
		for (i = 0; i < n; i ++)
			if ((b[i] == 0) && (a[i].pos[0] == 'G'))
			{
				b[i] = 1;
				order[t++] = i;
				break;
			}
		j = 0;
		for (i = 0; i < n; i ++)
			if ((b[i] == 0) && (a[i].pos[0] == 'D'))
			{
				b[i] = 1;
				order[t ++] = i;
				j ++;
				if (j == D) break;
			}
		j = 0;
		for (i = 0; i < n; i ++)
			if ((b[i] == 0) && (a[i].pos[0] == 'M'))
			{
				b[i] = 1;
				order[t ++] = i;
				j ++;
				if (j == M) break;
			}
		j = 0;
		for (i = 0; i < n; i ++)
			if ((b[i] == 0) && (a[i].pos[0] == 'S'))
			{
				b[i] = 1;
				order[t ++] = i;
				j ++;
				if (j == S) break;
			}
		if (t < 11) printf("IMPOSSIBLE TO ARRANGE\n");
		else
		{
			max = 0; maxn = 0;
			for (i = 0; i < t; i ++)
				if ((a[order[i]].time > max) || ((a[order[i]].time == max) && (a[order[i]].num > maxn)))
				{
					max = a[order[i]].time;
					maxn = a[order[i]].num;
					k = i;
				}
			printf("%d %s %s\n" , a[order[k]].num , a[order[k]].name , a[order[k]].pos);
			for (i = 0; i < t; i ++)
				if (i != k)
				{
					printf("%d %s %s\n" , a[order[i]].num , a[order[i]].name , a[order[i]].pos);
				}
		}
		printf("\n");
	}
	return 0;
}
