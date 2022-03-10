//PKU 3007
//将一个字符串分成2段，记为X，Y。X的反串为X'，Y的反串为Y'
//可以的组合X+Y , Y+X , X'+Y , Y+X' , X+Y' , Y'+X , X'+Y' , Y'+X'
//求可生成多少种不同的串，枚举
#include <stdio.h>
#include <string.h>

char str[600][80];
int num;

void insert(char* s)
{
int i , b;

	b = 1;
	for (i = 0; i < num; i ++)
		if (strcmp(s , str[i]) == 0) {b = 0; break;}
	if (b) {strcpy(str[num] , s); num ++;}
}

int main()
{
int m , L;
int i , j , L1 , L2;

char s[80];
char temp1[80] , temp2[80] , temp3[80] , temp4[80];
char ss[80];

	scanf("%d" , &m);
	while (m --)
	{
		scanf("%s" , s);
		L = strlen(s);
		num = 1; strcpy(str[0] , s);
		for (i = 1; i <	L; i ++)
		{
			for (j = 0; j < i; j ++) temp1[j] = s[j];
			temp1[j] = 0;
			L1 = j;
			while (j < L)
			{
				temp2[j - L1] = s[j];
				j ++;
			}
			temp2[j - L1] = 0;
			L2 = L - L1;
			if (L1 > 1)
			{
				strcpy(temp3 , temp1);
				strrev(temp3);
			}
			if (L2 > 1)
			{
				strcpy(temp4 , temp2);
				strrev(temp4);
			}
			// Y + X
			strcpy(ss , temp2);
			strcat(ss , temp1);
			insert(ss);
			if (L1 > 1)
			{
				// X'+ Y
				strcpy(ss , temp3);
				strcat(ss , temp2);
				insert(ss);
				// Y + X'
				strcpy(ss , temp2);
				strcat(ss , temp3);
				insert(ss);
			}
			if (L2 > 1)
			{
				// X + Y'
				strcpy(ss , temp1);
				strcat(ss , temp4);
				insert(ss);
				// Y'+ X
				strcpy(ss , temp4);
				strcat(ss , temp1);
				insert(ss);
			}
			if ((L1 > 1) && (L2 > 1))
			{
				// X'+Y'
				strcpy(ss , temp3);
				strcat(ss , temp4);
				insert(ss);
				// Y'+X'
				strcpy(ss , temp4);
				strcat(ss , temp3);
				insert(ss);
			}
		}
		printf("%d\n" , num);
	}
	return 0;
}