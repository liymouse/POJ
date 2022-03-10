#include <stdio.h>
#include <string.h>

char p[26][5] = {"4" , "|3" , "(" , "|)" , "3" , "|=" , "6" , "#" , "|" ,
"_|" , "|<" , "|_" , "|\\/|" , "|\\|" , "0" , "|0" , "(,)" , "|?" , "5" ,
"7" , "|_|" , "\\/" , "\\/\\/" , "><" , "-/" , "2"};
int L[26];

int main()
{
char str[110];
char s[500];
int f[500];
int Leng , i , j , k , b;

	for (i = 0; i < 26; i ++) L[i] = strlen(p[i]);

	while (scanf("%s" , str) == 1)
	{
		if (str[0] == 'e') break;
		memset(f , 0 , sizeof(f));
		Leng = strlen(str); s[0] = 0;
		for (i = 0; i < Leng; i ++)
			strcat(s , p[str[i]-'A']);
		Leng = strlen(s);
		f[0] = 1;
		for (i = 1; i <= Leng; i ++)
			for (k = 1; k <= 4; k ++)
				if (i - k >= 0)
				{
					for (j = i - k; j < i; j ++) str[j - i + k] = s[j];
					str[k] = 0;
					b = 0;
					for (j = 0; j < 26; j ++)
						if ((L[j] == k) && (strcmp(str , p[j]) == 0)) {b = 1; break;}
					if (b) f[i] += f[i - k];
				}
		;
		printf("%d\n" , f[Leng]);
	}
	return 0;
}