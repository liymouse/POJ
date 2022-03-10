#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAX 27

char s[100000];
int b[100000];

bool cmp(int &x , int &y)
{
	return x < y;
}

int main()
{
int n , m , i , L , t , x , y , p , q , num;
int c[MAX] , a[MAX];


	while (scanf("%s" , s) == 1)
	{
		if (strcmp(s , "END") == 0) break;
		L = strlen(s);
		n = L * 8;
		memset(c , 0 , sizeof(c));
		for (i = 0; i < L; i ++)
			if (s[i] == '_') c[26] ++;
			else c[s[i]-'A'] ++;
		num = 0;
		for (i = 0; i < MAX; i ++) if (c[i] > 0) a[num ++] = c[i];
		sort(a , a + num , cmp);
		if (num == 1) {printf("%d %d %.1lf\n" , n , a[0] , n * 1.0 / a[0]); continue;}
		t = 0; x = 0; y = 0; m = 0;
		memset(b , 0 , sizeof(b));
		while (1)
		{
			if ((t < num) && ((a[t] <= b[x]) || (b[x] == 0)))
			{
				p = a[t]; t ++;
			}
			else {p = b[x]; x ++;}
			if ((t < num) && ((a[t] <= b[x]) || (b[x] == 0)))
			{
				q = a[t]; t ++;
			}
			else {q = b[x]; x ++;}
			b[y] = p + q; m += b[y]; y ++;
			if ((t == num) && (x == y-1)) break;
		}
		printf("%d %d %.1lf\n" , n , m , n * 1.0 / m);
	}
	return 0;
}
