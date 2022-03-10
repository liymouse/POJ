#include <stdio.h>
#include <string.h>

int main()
{
char s1[110] , s2[110];
int b1[10] , b2[10];
int L1 , L2;
int n , i , j , b , ok , x , y;
char *p , *q;

	scanf("%d" , &n);
	while (n --)
	{
		scanf("%s %s" , s1 , s2);
		L1 = strlen(s1);
		L2 = strlen(s2);
		memset(b1 , 0 , sizeof(b1));
		memset(b2 , 0 , sizeof(b2));
		for (i = 0; i < L1; i ++) b1[s1[i]-'0'] ++;
		for (i = 0; i < L2; i ++) b2[s2[i]-'0'] ++;
		b = 0;
		for (i = 0; i < 10; i ++)
			if (((b1[i] == 0) && (b2[i])) || ((b2[i] == 0) && (b1[i]))) b ++;
		if (b == 0) printf("friends\n");
		else if (b > 4) printf("nothing\n");
		else
		{
			ok = 0;
			for (i = 0; i < L1-1; i ++)
			{
				x = s1[i] - '0';
				y = s1[i+1] - '0';
				if (!(((b1[x] == 1) && (b2[x] > 0)) || ((b1[y] == 1) && (b2[y] > 0))))
				{
					b1[x] --; b1[y] --;
					x --; y ++;
					if ((x >= 0) && (y < 10) && b2[x] && b2[y])
					{
						b1[x] ++; b1[y] ++;
						b = 0;
						for (j = 0; j < 10; j ++)
							if (((b1[j] == 0) && (b2[j])) || ((b2[j] == 0) && (b1[j]))) b ++;
						if (b == 0)
						{
							if (!((i == 0) && (x == 0))) { ok = 1; break; }
						}						
						b1[x] --; b1[y] --;
					}
					
					x += 2; y -= 2;
					if ((x < 10) && (y >= 0) && b2[x] && b2[y])
					{
						b1[x] ++; b1[y] ++;
						b = 0;
						for (j = 0; j < 10; j ++)
							if (((b1[j] == 0) && (b2[j])) || ((b2[j] == 0) && (b1[j]))) b ++;
						if (b == 0)	{ ok = 1; break; }
						b1[x] --; b1[y] --;
					}
					b1[x-1] ++; b1[y+1] ++;
				}
			}

			if (ok == 0)
			for (i = 0; i < L2-1; i ++)
			{
				x = s2[i] - '0';
				y = s2[i+1] - '0';
				if (!(((b2[x] == 1) && (b1[x] > 0)) || ((b2[y] == 1) && (b1[y] > 0))))
				{
					b2[x] --; b2[y] --;
					x --; y ++;
					if ((x >= 0) && (y < 10) && b1[x] && b1[y])
					{
						b2[x] ++; b2[y] ++;
						b = 0;
						for (j = 0; j < 10; j ++)
							if (((b1[j] == 0) && (b2[j])) || ((b2[j] == 0) && (b1[j]))) b ++;
						if (b == 0)
						{
							if (!((i == 0) && (x == 0))) { ok = 1; break; }
						}
						b2[x] --; b2[y] --;
					}
					x += 2; y -= 2;
					if ((x < 10) && (y >= 0) && b1[x] && b1[y])
					{
						b2[x] ++; b2[y] ++;
						b = 0;
						for (j = 0; j < 10; j ++)
							if (((b1[j] == 0) && (b2[j])) || ((b2[j] == 0) && (b1[j]))) b ++;
						if (b == 0)	{ ok = 1; break; }
						b2[x] --; b2[y] --;
					}
					b2[x-1] ++; b2[y+1] ++;
				}
			}

			if (ok) printf("almost friends\n");
			else printf("nothing\n");
		}
	}
	return 0;
}