#include <stdio.h>
#include <string.h>

int main()
{
int a[40] , b[40] , d[80];
char s[41];
int i , j , La , Lb , Lc , L;

	scanf("%s" , s);
	La = strlen(s);
	for (i = 0; i < La; i ++)
		a[La-i-1] = s[i] - '0';
	scanf("%s" , s);
	Lb = strlen(s);
	for (i = 0; i < Lb; i ++)
		b[Lb-i-1] = s[i] - '0';
	memset(d , 0 , sizeof(d));
	for (i = 0; i < La; i ++)
		for (j = 0; j < Lb; j ++)
		{
			d[i + j] += a[i] * b[j];
			if (d[i+j] > 9)
			{
				d[i+j+1] += d[i+j]/10;
				d[i+j] %= 10;
			}
		}
	if (d[La + Lb - 1] == 0) L = La + Lb - 1; else L = La + Lb;
	for (i = L-1; i >= 0; i --) printf("%d" , d[i]);
	printf("\n");
	return 0;
}