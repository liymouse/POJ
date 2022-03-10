#include <stdio.h>
#include <string.h>

int main()
{
int p[8][3] = {{0 , 1 , 2} , {3 , 4 , 5} , {6 , 7 , 8} , {0 , 3 ,6} , {1 ,4 ,7} , {2 , 5 , 8} , {0 , 4 , 8} , {2 , 4, 6}};
int i , n , j;
int numx , numo;
int x[9];
int okx , oko , b;
char s[13];

	n = 9;
	while (scanf("%s" , s) == 1)
	{
		if (s[0] == 'e') break;
		numx = 0; numo = 0;
		for (i = 0; i < n; i ++)
			if (s[i] == 'X') numx ++;
			else if (s[i] == 'O') numo ++;
		if (!((numx == numo + 1) || (numx == numo))) printf("invalid\n");
		else
		{
			memset(x , 0 , sizeof(x));
			okx = 0;
			for (i = 0; i < 8; i ++)
			{
				b = 1;
				for (j = 0; j < 3; j ++)
					if (s[p[i][j]] != 'X') {b = 0; break;}
				if (b)
				{
					okx ++;
					for (j = 0; j < 3; j ++) x[p[i][j]] ++;
				}
			}
			oko = 0;
			for (i = 0; i < 8; i ++)
			{
				b = 1;
				for (j = 0; j < 3; j ++)
					if (s[p[i][j]] != 'O') {b = 0; break;}
				if (b) oko ++;
			}
			if ((okx > 0) && (oko > 0)) printf("invalid\n");
			else if ((okx == 2) && (oko == 0))
			{
				if (numx != numo + 1) printf("invalid\n");
				else
				{
					j = 0;
					for (i = 0; i < n; i ++) if (x[i] == 2) {j = 1; break;}
					if (j) printf("valid\n");
					else printf("invalid\n");
				}
			}
			else if ((okx == 0) && (oko == 2)) printf("invalid\n");
			else
			{
				if (okx)
				{
					if (numx == numo + 1) printf("valid\n");
					else printf("invalid\n");
				}
				else if (oko)
				{
					if (numx == numo) printf("valid\n");
					else printf("invalid\n");
				}
				else if ((oko + okx == 0) && (numx + numo < 9)) printf("invalid\n");
				else printf("valid\n");
			}
		}
	}
	return 0;
}