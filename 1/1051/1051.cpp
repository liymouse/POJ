#include <stdio.h>
#include <string.h>

char s[101];
int a[400] , order[100];
int num , k;

void change1()
{
int i , t , L;

	t = 0; num = 0; k = 0;
	L = strlen(s);
	for (i = 0; i < L; i ++)
	{
		switch(s[i])
		{
			case 'A' : a[k ++] = 0; a[k ++] = 1; order[num ++] = 2;
				break;
			case 'B' : a[k ++] = 1; a[k ++] = 0; a[k ++] = 0; a[k ++] = 0; order[num ++] = 4;
				break; 
			case 'C' : a[k ++] = 1; a[k ++] = 0; a[k ++] = 1; a[k ++] = 0; order[num ++] = 4;
				break;
			case 'D' : a[k ++] = 1; a[k ++] = 0; a[k ++] = 0; order[num ++] = 3;
				break;
			case 'E' : a[k ++] = 0; order[num ++] = 1;
				break;
			case 'F' : a[k ++] = 0; a[k ++] = 0; a[k ++] = 1; a[k ++] = 0; order[num ++] = 4;
				break;
			case 'G' : a[k ++] = 1; a[k ++] = 1; a[k ++] = 0; order[num ++] = 3;
				break;
			case 'H' : a[k ++] = 0; a[k ++] = 0; a[k ++] = 0; a[k ++] = 0; order[num ++] = 4;
				break;
			case 'I' : a[k ++] = 0; a[k ++] = 0; order[num ++] = 2;
				break;
			case 'J' : a[k ++] = 0; a[k ++] = 1; a[k ++] = 1; a[k ++] = 1; order[num ++] = 4;
				break;
			case 'K' : a[k ++] = 1; a[k ++] = 0; a[k ++] = 1; order[num ++] = 3;
				break;
			case 'L' : a[k ++] = 0; a[k ++] = 1; a[k ++] = 0; a[k ++] = 0; order[num ++] = 4;
				break;
			case 'M' : a[k ++] = 1; a[k ++] = 1; order[num ++] = 2;
				break;
			case 'N' : a[k ++] = 1; a[k ++] = 0; order[num ++] = 2;
				break;
			case 'O' : a[k ++] = 1; a[k ++] = 1; a[k ++] = 1; order[num ++] = 3;
				break;
			case 'P' : a[k ++] = 0; a[k ++] = 1; a[k ++] = 1; a[k ++] = 0; order[num ++] = 4;
				break;
			case 'Q' : a[k ++] = 1; a[k ++] = 1; a[k ++] = 0; a[k ++] = 1; order[num ++] = 4;
				break;
			case 'R' : a[k ++] = 0; a[k ++] = 1; a[k ++] = 0; order[num ++] = 3;
				break;
			case 'S' : a[k ++] = 0; a[k ++] = 0; a[k ++] = 0; order[num ++] = 3;
				break;
			case 'T' : a[k ++] = 1; order[num ++] = 1;
				break;
			case 'U' : a[k ++] = 0; a[k ++] = 0; a[k ++] = 1; order[num ++] = 3;
				break;
			case 'V' : a[k ++] = 0; a[k ++] = 0; a[k ++] = 0; a[k ++] = 1; order[num ++] = 4;
				break;
			case 'W' : a[k ++] = 0; a[k ++] = 1; a[k ++] = 1; order[num ++] = 3;
				break;
			case 'X' : a[k ++] = 1; a[k ++] = 0; a[k ++] = 0; a[k ++] = 1; order[num ++] = 4;
				break;
			case 'Y' : a[k ++] = 1; a[k ++] = 0; a[k ++] = 1; a[k ++] = 1; order[num ++] = 4;
				break;
			case 'Z' : a[k ++] = 1; a[k ++] = 1; a[k ++] = 0; a[k ++] = 0; order[num ++] = 4;
				break;
			case '_' : a[k ++] = 0; a[k ++] = 0; a[k ++] = 1; a[k ++] = 1; order[num ++] = 4;
				break;
			case ',' : a[k ++] = 0; a[k ++] = 1; a[k ++] = 0; a[k ++] = 1; order[num ++] = 4;
				break;
			case '.' : a[k ++] = 1; a[k ++] = 1; a[k ++] = 1; a[k ++] = 0; order[num ++] = 4;
				break;
			case '?' : a[k ++] = 1; a[k ++] = 1; a[k ++] = 1; a[k ++] = 1; order[num ++] = 4;
				break;
		}
	}
}

void change2()
{
char p[5][16] = {{' '} , 
				{'E','T'} , 
				{'I','A','N','M'} , 
				{'S','U','R','W','D','K','G','O'} , 
				{'H','V','F','_','L',',','P','J','B','X','C','Y','Z','Q','.','?'}};
int q[4] = {1 , 2 , 4 , 8};
int i , t , x , y;

	t = 0; k = 0;
	for (i = num-1; i >= 0; i --)
	{
		x = order[i]; y = 0;
		while (x > 0)
		{
			x --; y += a[k++] * q[x];
		}
		s[t ++] = p[order[i]][y];
	}
	s[t] = 0;
}

int main()
{
int n , t , i;

	scanf("%d" , &n);
	for (t = 1; t <= n; t ++)
	{
		scanf("%s" , s);
		change1();
		change2();
		printf("%d: %s\n" , t , s);
	}
	return 0;
}