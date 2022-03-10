#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

bool cmp(const char &x , const char &y)
{
	return x < y;
}

int main()
{
char s[201];
int a[26] , i , L , k;

	scanf("%s" , s);
	L = strlen(s);
	sort(s , s + L , cmp);
	printf("%s\n" , s);
	while (1)
	{
		k = L-1;
		memset(a , 0 , sizeof(a));
		while ((k > 0) && (s[k-1] >= s[k]))
		{
			a[s[k]-'a'] ++;
			k --;
		}
		if (k == 0) break;
		a[s[k-1] - 'a'] ++;
		a[s[k] - 'a'] ++;
		for (i = 0; i < 26; i ++) if ((a[i] > 0) && (i > s[k-1]-'a')) {a[i] --; break;}
		s[k-1] = i + 'a';
		for (i = 0; i < 26; i ++)
			while (a[i] > 0) {s[k ++] = i + 'a'; a[i] --;}
		printf("%s\n" , s);
	}
	return 0;
}