#include <stdio.h>
#include <algorithm>
using namespace std;

struct kk {char word[17]; int v;} a[1000];

bool cmp(kk &x , kk &y)
{
	return strcmp(x.word , y.word) < 0;
}

int main()
{
int n , m , i , x , y , z , tot;
char s[30];

	scanf("%d %d" , &n , &m);
	for (i = 0; i < n; i ++)
		scanf("%s %d" , a[i].word , &a[i].v);
	sort(a , a + n , cmp);
	for (i = 0; i < m; i ++)
	{
		tot = 0;
		while (scanf("%s" , s) == 1)
		{
			if (s[0] == '.') break;
			x = 0; y = n - 1;
			while (x <= y)
			{
				z = (x + y) / 2;
				if (strcmp(a[z].word , s) > 0) y = z - 1;
				else if (strcmp(a[z].word , s) < 0) x = z + 1;
				else break;
			}
			if (strcmp(a[z].word , s) == 0) tot += a[z].v;
		}
		printf("%d\n" , tot);
	}
	return 0;
}