#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n,m,l;
char st[100],a[100],b[100],c,d;
bool ok;

int main()
{
int i,j,k;

	m = 0;
	while (true)
	{
		scanf("%s",st);
		if (st[0] == '*'){return 0;}
		printf("%s",st);
		ok = true;
		l = strlen(st);
		for (i=1;i<=l-2;i++)
		{
			n = 0;
			for (j=0;j<=l-1;j++)
			{
				if (i+j>l-1){break;}
				n++;
				a[n] = st[j];
				b[n] = st[j+i];
			}
			for (j=1;j<=n-1;j++)
			{
				for (k=j+1;k<=n;k++)
				{
					if (a[j] == a[k] && b[j] == b[k])
					{
						ok = false;
						break;
					}
				}
			}
		}
		if (ok)
		{
			printf(" is surprising.\n");
		}
		else
		{
			printf(" is NOT surprising.\n");
		}
	}
}


