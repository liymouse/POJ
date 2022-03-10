#include <stdio.h>
#include <string.h>

int main()
{
	int n , i , L , j , x , num , p , k , s;
	char str[1050] , res[2000] , temp[10];
	scanf("%d" , &n);
	for (j = 0; j < n; j ++)
	{
		scanf("%s" , str);
		L = strlen(str);
		p = 0; x = -1; num = 0;
		for (i = 0; i <= L; i ++)
		{
			if (str[i] != x)
			{
				if (x != -1)
				{
					k = 0;
					while (num)
					{
						temp[k ++] = num % 10 + '0';
						num /= 10;
					}
					for (s = k-1; s >= 0; s --)
						res[p ++] = temp[s];
					res[p ++] = x;
				}
				x = str[i];
				num = 1;
			}
			else num ++;
		}
		res[p] = 0;
		printf("%s\n" , res);
	}
	return 0;
}
