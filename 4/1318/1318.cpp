#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

struct kk {char word[7]; int b[26];} a[100];
bool cmp(kk &x , kk &y)
{
	return strcmp(x.word , y.word) < 0;
}

int main()
{
int i , j , n , bo , have;
char s[7] , num[26];

	n = 0;
	while (scanf("%s" , a[n++].word) == 1)
	{
		if (strcmp("XXXXXX" , a[n-1].word) == 0) break;
	}
	n --;
	sort(a , a + n , cmp);
	for (i = 0; i < n; i ++)
	{
		memset(a[i].b , 0 , sizeof(a[i].b));
		j = 0;
		while (a[i].word[j] > 0) a[i].b[a[i].word[j++] - 'a'] ++;
	}
	while (scanf("%s" , s) == 1)
	{
		if (strcmp("XXXXXX" , s) == 0) break;
		i = 0;
		memset(num , 0 , sizeof(num));
		while (s[i] > 0) num[s[i ++] - 'a'] ++;
		have = 0;
		for (i = 0; i < n; i ++)
		{
			bo = 0;
			for (j = 0; j < 26; j ++)
				if (num[j] != a[i].b[j]) {bo = 1; break;}
				if (bo == 0) {have = 1; printf("%s\n" , a[i].word);}
		}
		if (have == 0) printf("NOT A VALID WORD\n");
		printf("******\n");
	}
	return 0;
}
