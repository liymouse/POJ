#include <stdio.h>
#include <string.h>

typedef struct kk
{
	int v;
	struct kk *L , *R;
}kk , *Node;

void insert(Node h , int x)
{
Node p;

	if (x < h -> v)
	{
		if (h -> L != NULL) insert(h -> L , x);
		else
		{
			p = new(kk);
			p -> v = x; p -> L = NULL; p -> R = NULL;
			h -> L = p;
		}
	}
	else
	{
		if (h -> R != NULL) insert(h -> R , x);
		else
		{
			p = new(kk);
			p -> v = x; p -> L = NULL; p -> R = NULL;
			h -> R = p;
		}
	}
}

void print(Node h)
{
	printf("%c" , h -> v + 'A');
	if (h -> L != NULL) print(h -> L);
	if (h -> R != NULL) print(h -> R);
}

int main()
{
char s[26][27];
int n , L , i , j;
Node head;

	n = 0;
	while (scanf("%s" , s[n]) == 1)
	{
		n ++;
		if ((s[n-1][0] == '*') || (s[n-1][0] == '$'))
		{
			n --;
			head = new(kk);
			head->v = 30; head->L = NULL;
			for (i = n-1; i >= 0; i --)
			{
				L = strlen(s[i]);
				for (j = 0; j < L; j ++)
					insert(head , s[i][j]-'A');
			}
			print(head -> L);
			printf("\n");
			if (s[n][0] == '$') break;
			n = 0;
		}
	}
	return 0;
}