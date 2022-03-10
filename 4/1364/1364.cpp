#include <stdio.h>
#include <string.h>


int n , m , d[128] , edge[128][3]; 

bool Bellman_Ford(int s)
{	
	memset(d , 0 , sizeof(d));
	bool over;		
	for (int i = 0; i <= n; i++)
	{
		over = 1;
		for (int j = 0; j < m; j++)
		{
			if (d[edge[j][0]] > d[edge[j][1]]+edge[j][2])
			{
				over = 0;
				d[edge[j][0]] = d[edge[j][1]]+edge[j][2];
			}
		}
		if (over) break;
	}
	return over;
}

int main()
{
int a , b , c;
char op[3];

	while (scanf("%d", &n) && n)
	{
		scanf("%d", &m);
		for (int i = 0; i < m; i++)
		{
			scanf("%d %d %s %d", &a, &b, op, &c);
			if (strcmp(op, "gt") == 0)
			{
				edge[i][0] = a-1;
				edge[i][1] = a+b;
				edge[i][2] = -(c+1);
			}
			else	
			{		
				edge[i][0] = a+b;	
				edge[i][1] = a-1;	
				edge[i][2] = c-1;	
			}	
		}		
		if (Bellman_Ford(edge[0][0]))	
			printf("lamentable kingdom\n");	
		else		
			printf("successful conspiracy\n");	
	}	
	return 0;
}