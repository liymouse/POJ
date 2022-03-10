#include <stdio.h>
#include <string.h>

int slump(char s[])
{
int L , i , j;
char s1[61];

	if ((s[0] != 'D') && (s[0] != 'E')) return 0;
	if (s[1] != 'F') return 0;
	else
	{
		L = strlen(s);
		i = 1;
		while (s[i] == 'F') i ++;
		if (i == L) return 0;
		if ((i == L-1) && (s[i] == 'G')) return 1;
		else
		{
			for (j = i; j < L; j ++) s1[j-i] = s[j];
			s1[j-i] = 0;
			if (slump(s1) == 1) return 1;
			else return 0;
		}
	}
}

int slimp(char s[])
{
int L , i;
char s1[61];

	if (s[0] != 'A') return 0;
	L = strlen(s);
	if (L == 2)
	{
		if (s[1] == 'H') return 1;
		else return 0;
	}
	else
	{
		if ((s[1] == 'B') && (s[L-1] == 'C'))
		{
			for (i = 2; i < L-1; i ++) s1[i-2] = s[i];
			s1[i-2] = 0;
			if (slimp(s1) == 1) return 1;
			else return 0;
		}
		else if (((s[1] == 'D') || (s[1] == 'E')) && (s[L-1] == 'C'))
		{
			for (i = 1; i < L-1; i ++) s1[i-1] = s[i];
			s1[i-1] = 0;
			if (slump(s1) == 1) return 1;
			else return 0;
		}
		else return 0;
	}
}

int main()
{
int n , i , j , k , b , L;
char s[61] , s1[61] , s2[61];

	scanf("%d" , &n);
	printf("SLURPYS OUTPUT\n");
	for (i = 0; i < n; i ++)
	{
		scanf("%s" , s);
		b = 0; L = strlen(s);
		for (j = 0; j < L-1; j ++)
		{
			for (k = 0; k <= j; k ++) s1[k] = s[k];
			s1[k] = 0;
			for (k = j + 1; k < L; k ++) s2[k-j-1] = s[k];
			s2[k-j-1] = 0;
			if ((slimp(s1) == 1) && (slump(s2) == 1)) {b = 1; break;}
		}
		if (b) printf("YES\n"); else printf("NO\n");
	}
	printf("END OF OUTPUT\n");
	return 0;
}