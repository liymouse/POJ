#include <stdio.h>
#include <string.h>

char s[1005];

int check()
{
int i , L;

	L = strlen(s);
	i = 0;
	if (s[i] == '+' || s[i] == '-') i ++;
	if (i >= L) return 0;	//加减号后面没有东西
	if (s[i] < '0' || s[i] > '9') return 0; //加减号后面没有数字
	while ((s[i] >= '0') && (s[i] <= '9')) i ++;
	if (i >= L) return 1;	//整数
	if (s[i] == '.')
	{
		i ++;
		if (i >= L) return 0;	//小数点后没东西
		if ((s[i] < '0') || (s[i] > '9')) return 0;	//小数点后没数字
		while ((s[i] >= '0') && (s[i] <= '9')) i ++;
		if (i >= L) return 1;	//小数
	}
	if (s[i] == 'e' || s[i] == 'E')	//有指数
	{
		i ++;
		if (i >= L) return 0;	//e后面没东西
		if (s[i] == '+' || s[i] == '-') i ++;
		if (i >= L) return 0;	//加减号后面没东西
		if (s[i] < '0' || s[i] > '9') return 0;  //加减号后面不是数字
		while ((s[i] >= '0') && (s[i] <= '9')) i ++;
		if (i >= L) return 1;
		else return 0;
	}
	return 0;
}

int main()
{
int t;

	scanf("%d" , &t);
	while (t --)
	{
		scanf("%s" , s);
		if (check()) printf("LEGAL\n"); else printf("ILLEGAL\n");
	}
	return 0;
}
