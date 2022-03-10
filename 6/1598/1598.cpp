#include <stdio.h>
#include <string.h>

int main()
{
int k , e , i , j , t , x , h;
char keyw[20][21];
char s[20][71] , word[20] , L;
int num[20] , max;

	h = 0;
	while (scanf("%d %d" , &k , &e) == 2)
	{
		for (i = 0; i < k; i ++)
			scanf("%s\n" , keyw[i]);
		memset(num , 0 , sizeof(num));
		for (i = 0; i < e; i ++)
		{
			gets(s[i]); j = 0; L = strlen(s[i]);
			for (t = 0; t < L; t ++)
			{
				if (((s[i][t] >= 'A') && (s[i][t] <= 'Z')) || ((s[i][t] >= 'a') && (s[i][t] <= 'z')))
				{
					word[j ++] = s[i][t];
				}
				else if (j > 0)
				{
					word[j] = 0;
					strlwr(word);
					for (x = 0; x < k; x ++)
						if (strcmp(word , keyw[x]) == 0) {num[i] ++; break;}
					j = 0;
				}
			}
			if (j > 0)
			{
				word[j] = 0;
				strlwr(word);
				for (x = 0; x < k; x ++)
					if (strcmp(word , keyw[x]) == 0) {num[i] ++; break;}
				j = 0;
			}
		}
		h ++; max = 0;
		printf("Excuse Set #%d\n" , h);
		for (i = 0; i < e; i ++) if (num[i] > max) max = num[i];
		for (i = 0; i < e; i ++) if (num[i] == max) printf("%s\n" , s[i]);
		printf("\n");
	}
	return 0;
}