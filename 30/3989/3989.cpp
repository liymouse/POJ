#include <stdio.h>
#include <algorithm>
using namespace std;

typedef long long i64d;

int have[5];
char s[3][12];
int used[10];
int v[5];
int res;

void find(int x)
{
	if (x == 5)
	{
		int ok = 1;
		i64d k[3] = {0};
		for (int i = 0; i < 3; i ++)
			if (v[s[i][0]-'A'] == 0 && s[i][1] != 0) return;
		for (int i = 0; i < 3; i ++)
			for (int j = 0; s[i][j] != 0; j ++)
				k[i] = k[i] * 10 + v[s[i][j] - 'A'];
		if (k[0] + k[1] == k[2]) res ++;//{printf("%d + %d = %d\n" , k[0] , k[1] , k[2]); res ++;}
		if (k[0] - k[1] == k[2]) res ++;//{printf("%d - %d = %d\n" , k[0] , k[1] , k[2]); res ++;}
		if (k[0] * k[1] == k[2]) res ++;//{printf("%d * %d = %d\n" , k[0] , k[1] , k[2]); res ++;}
		if (k[1] > 0 && k[0] % k[1] == 0 && k[0] / k[1] == k[2]) res ++;//{printf("%d / %d = %d\n" , k[0] , k[1] , k[2]); res ++;}
		return;
	}
	if (have[x] == 0) find(x + 1);
	else
	{
		for (int i = 0; i < 10; i ++)
			if (!used[i])
			{
				v[x] = i;
				used[i] = 1;
				find(x + 1);
				used[i] = 0;
			}
	}
}
int main()
{
	int n;
	scanf("%d" , &n);
	while (n --)
	{
		scanf("%s %s %s" , s[0] , s[1] , s[2]);
		for (int i = 0; i < 5; i ++) have[i] = 0;
		for (int i = 0; i < 3; i ++)
			for (int j = 0; s[i][j] != 0; j ++) have[s[i][j] - 'A'] = 1;
		for (int i = 0; i < 10; i ++) used[i] = 0;
		res = 0;
		find(0);
		printf("%d\n" , res);
	}
	return 0;
}
