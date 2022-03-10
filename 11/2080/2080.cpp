#include <stdio.h>

int main()
{
char s[7][11] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
int mo[12] = {31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31};
int n , year , day , mm , dd , i , x;

	while (scanf("%d" , &n) == 1)
	{
		if (n == -1) break;
		x = n % 7;
		year = 2000; day = 366; n ++;
		while (n > day)
		{
			n -= day;
			year ++;
			if (year % 4 != 0) day = 365;
			else if ((year % 100 == 0) && (year % 400 != 0)) day = 365;
				else day = 366;
		}
		if (day == 365) mo[1] = 28; else mo[1] = 29;
		mm = 1;
		for (i = 0; i < 12; i ++)
			if (n > mo[i]) {mm ++; n -= mo[i];} else break;
		printf("%d-" , year);
		if (mm < 10) printf("0");
		printf("%d-" , mm);
		if (n < 10) printf("0");
		printf("%d " , n);
		printf("%s\n" , s[x]);
	}
	return 0;
}