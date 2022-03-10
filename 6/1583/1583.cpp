#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define WORD ((s[i] >= 'A') && (s[i] <= 'Z')) || ((s[i] >= 'a') && (s[i] <= 'z')) || ((s[i] >= '0') && (s[i] <= '9'))
#define PUN (s[i]==',')||(s[i]=='.')||(s[i]==';')||(s[i]=='\'')||(s[i]=='`')||(s[i]=='\"')||(s[i]=='(')||(s[i]==')')||(s[i]=='/')||(s[i]==':')||(s[i]=='-')

struct kk{char word[81]; int num;}a[5000];

bool cmp(kk &x , kk &y)
{
	if (x.num == y.num) return strcmp(x.word , y.word) < 0;
	else return x.num > y.num;
}

int main()
{
char s[81] , w[81];
int i , j , k , L , n , t;

	n = 0;
	while (scanf("%s" , &s) == 1)
	{
		L = strlen(s); j = 0;
		for (i = 0; i < L; i ++)
		{
			if (WORD) w[j ++] = s[i];
			else if (j > 0)
			{
				w[j] = 0;
				strlwr(w);
				t = -1;
				for (k = 0; k < n; k ++) if (strcmp(w , a[k].word) == 0) {t = k; break;}
				if (t == -1) {strcpy(a[n].word , w); a[n].num = 1; n ++;}
				else a[t].num ++;
				j = 0;
			}
		}
		if (j > 0)
		{
			w[j] = 0;
			strlwr(w);
			t = -1;
			for (k = 0; k < n; k ++) if (strcmp(w , a[k].word) == 0) {t = k; break;}
			if (t == -1) {strcpy(a[n].word , w); a[n].num = 1; n ++;}
			else a[t].num ++;
		}
	}
	sort(a , a + n , cmp);
	t = a[0].num;
	printf("%d occurrences\n" , t);
	for (i = 0; i < n; i ++)
		if (a[i].num == t) printf("%s\n" , a[i].word);
		else break;
	return 0;
}