#include <stdio.h>
#include <string.h>

int main()
{
int i , Lsum , Ls;
int sum[201] = {0};
char s[201];

	Lsum = 1;
	while (scanf("%s" , s) == 1)
	{
		if (strcmp(s , "0") == 0) 
		{
			for (i = Lsum-1; i >= 0; i --) printf("%d" , sum[i]);
			printf("\n");
			continue;
		}
		Ls = strlen(s);
		strrev(s);
		while ((Ls > 0) && (s[Ls - 1] == '0')) Ls --;
		for (i = 0; i < Ls; i ++)
		{
			sum[i] += s[i] - '0';
			if (sum[i] > 9) {sum[i + 1] ++; sum[i] -= 10;}
		}
		if (Lsum < Ls) Lsum = Ls;
		if (sum[Lsum] > 0) Lsum ++;
	}
	return 0;
}