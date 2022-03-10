#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
char back1[200] = {0} , back2[200] = {0};
char fac1[200] = {0} , fac2[200] = {0} , c1 , c2;
int num1 , num2 , b1 , b2 , f1 , f2 , top1 , top2;
int tot , win , first;
int i;

	//freopen("output.txt" , "w" , stdout);
	gets(back1); gets(back2);
	num1 = strlen(back1); num2 = num1;  tot = 0;
	b1 = 0; b2 = 0; f1 = 0; f2 = 0; top1 = num1; top2 = num2;
	while (tot < 1000)
	{
		tot ++;
		if (tot >= 1000) break;
		if (b1 < num1) c1 = back1[b1++];
		else
		{
			strcpy(back1 , fac1);
			num1 = strlen(back1);
			if (num1 == 0) {win = 1; break;}
			b1 = 1;
			c1 = back1[0];
			memset(fac1 , 0 , sizeof(fac1));
			f1 = 0;
		}
		if (b2 < num2) c2 = back2[b2++];
		else
		{
			strcpy(back2 , fac2);
			num2 = strlen(back2);
			if (num2 == 0) {win = 0; break;}
			b2 = 1;
			c2 = back2[0];
			memset(fac2 , 0 , sizeof(fac2));
			f2 = 0;
		}
		fac1[f1 ++] = c1; fac2[f2 ++] = c2;
		if (c1 == c2)
		{
			printf("Snap! for ");
			first = (rand()/99)%2;
			if (first == 0)
			{
				printf("Jane: ");
				strcat(fac1 , fac2);
				f1 += f2;
				memset(fac2 , 0 , sizeof(fac2));
				f2 = 0;
				for (i = f1 - 1; i >= 0; i --) printf("%c" , fac1[i]);
				printf("\n");
			}
			else
			{
				printf("John: ");
				strcat(fac2 , fac1);
				f2 += f1;
				f1 = 0;
				memset(fac1 , 0 , sizeof(fac1));
				for (i = f2 - 1; i >= 0; i --) printf("%c" , fac2[i]);
				printf("\n");
			}
		}
	}
	if (tot > 1000) printf("Keeps going and going ...\n");
	else
	{
		if (win == 0) printf("Jane wins.\n");
		else printf("John wins.\n");
	}
	return 0;
}
