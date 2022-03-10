#include <stdio.h>
#include <string.h>

char num1[6] , num2[9];
int L;

/*
 A  | V    U    C    D
------------------------
 V  | V    U    C    D
 U  | U    C    D    V,U
 C  | C    D    V,U  U,U
 D  | D    V,U  U,U  C,U
*/
int change(char c)
{
	if (c == 'V') return 0;
	if (c == 'U') return 1;
	if (c == 'C') return 2;
	if (c == 'D') return 3;
}

char exchange(int x)
{
	if (x == 0) return 'V';
	if (x == 1) return 'U';
	if (x == 2) return 'C';
	if (x == 3) return 'D';
}

void add()
{
int i;
int a[5] = {0} , b[8] = {0};

	for (i = 0; i < 5; i ++) a[i] = change(num1[i]);
	for (i = 0; i < L; i ++) b[i] = change(num2[i]);
	for (i = 0; i < 5; i ++) b[i] += a[i];
	for (i = 0; i < L; i ++) if (b[i] > 3) {b[i+1] += b[i] / 4; b[i] %= 4;}
	while (b[L] > 0) L ++;
	for (i = 0; i < L; i ++) num2[i] = exchange(b[i]);
}

void right()
{
int i;
	
	for (i = 0; i < L; i ++) num2[i] = num2[i+1];
	num2[L-1] = 'V';
}

void Left()
{
int i;

	for (i = L-1; i >= 0; i --) num2[i+1] = num2[i];
	num2[0] = 'V';
	L ++;
}

int main()
{
char s[9];
int n , h , i;

	scanf("%d" , &n);
	printf("COWCULATIONS OUTPUT\n");
	for (h = 0; h < n; h ++)
	{
		scanf("%s" , s);
		for (i = 0; i < 5; i ++) num1[i] = s[5-i-1];
		scanf("%s" , s);
		for (i = 0; i < 5; i ++) num2[i] = s[5-i-1];
		L = 5;
		for (i = 0; i < 3; i ++)
		{
			scanf("%s" , s);
			switch (s[0])
			{
				case 'A' : add();
				break;
				case 'R' : right();
				break;
				case 'L' : Left();
				break;
			}
		}
		scanf("%s" , s);
		for (i = L; i < 8; i ++) num2[i] = 'V'; num2[8] = 0;
		strrev(num2);
		if (strcmp(s , num2) == 0) printf("YES\n"); else printf("NO\n");
	}
	printf("END OF OUTPUT\n");
	return 0;
}