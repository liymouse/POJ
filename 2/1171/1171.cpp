#include <stdio.h>
#include <string.h>

int p[26] = {2 , 5 , 4 , 4 , 1 , 6 , 5 , 5 , 1 , 7 , 6 , 3 , 5 , 2 , 3 , 5 , 7 , 2 , 1 , 2 , 4 , 6 , 6 , 7 , 5 , 7};
int main()
{
int n , i , j , k , ok;
int a[26] , b[26];
char s3[35 * 6][8]; //P(7 , 3)3个字母单词的数量
int num3;
char s4[35 * 24][8]; //P(7 , 4)4个字母单词的数量
int num4;
char s[8];
int score3[35 * 6];
int score4[35 * 24];
int max , tempscore;

	scanf("%s" , s);
	n = 1; k = 0; num3 = 0; num4 = 0; max = 0;
	memset(a , 0 , sizeof(a));
	while (s[k]) { a[s[k]-'a'] ++; k ++; }
	while (1)
	{
		scanf("%s" , s);
		if (s[0] == '.') break;
		n ++;

		k = 0; tempscore = 0;
		memset(b , 0 , sizeof(b));
		while (s[k]) { b[s[k]-'a'] ++; tempscore += p[s[k]-'a']; k ++; }
		ok = 1;
		for (i = 0; i < 26; i ++) if (b[i] > a[i]) {ok = 0; break;}
		if (!ok) continue;
		if (tempscore > max) max = tempscore;
		if (k == 3)
		{
			strcpy(s3[num3] , s);
			score3[num3] = tempscore;
			num3 ++;
		}
		else if (k == 4)
		{
			strcpy(s4[num4] , s);
			score4[num4] = tempscore;
			num4 ++;
		}
	}
	for (i = 0; i < num3; i ++)
		for (j = i + 1; j < num3; j ++)
			if (score3[i] + score3[j] > max)
			{
				memset(b , 0 , sizeof(b));
				k = 0;
				while (s3[i][k]) {b[s3[i][k] - 'a'] ++; k ++;}
				k = 0;
				while (s3[j][k]) {b[s3[j][k] - 'a'] ++; k ++;}
				ok = 1;
				for (k = 0; k < 26; k ++) if (b[k] > a[k]) {ok = 0; break;}
				if (ok) max = score3[i] + score3[j];
			}
	for (i = 0; i < num3; i ++)
		for (j = 0; j < num4; j ++)
			if (score3[i] + score4[j] > max)
			{
				memset(b , 0 , sizeof(b));
				k = 0;
				while (s3[i][k]) {b[s3[i][k] - 'a'] ++; k ++;}
				k = 0;
				while (s4[j][k]) {b[s4[j][k] - 'a'] ++; k ++;}
				ok = 1;
				for (k = 0; k < 26; k ++) if (b[k] > a[k]) {ok = 0; break;}
				if (ok) max = score3[i] + score4[j];
			}
	printf("%d\n" , max);
	return 0;
}
