//����һ������ͼ�����ж��Ƿ����ŷ����·���������һ��ŷ����·
#include <stdio.h>
#include <string.h>

struct stack{int top , node[210];} f; //����Ķ�ջ
int a[201][201]; //ͼ���ڽӾ���
int n;

void dfs(int x)
{
int i;

	f.top ++; f.node[f.top] = x;
	for (i = 1; i <= n; i ++)
		if (a[i][x] > 0) {a[i][x] = 0; a[x][i] = 0; dfs(i); break;}
}

void Euler(int x)
{
int i , b;

	f.top = 0; f.node[f.top] = x;
	while (f.top >= 0)
	{
		b = 0;
		for (i = 1; i <= n; i ++) if (a[f.node[f.top]][i] > 0) {b = 1; break;}
		if (b == 0) {printf("%d " , f.node[f.top]); f.top --;}
		else {f.top --; dfs(f.node[f.top+1]);}
	}
}

int main()
{
int m , s , t , num , i , j , start;

	freopen("Euler.txt" , "r" , stdin);
	//input
	scanf("%d %d" , &n , &m); //n������  m����
	memset(a , 0 , sizeof(a));
	for (i = 0; i < m; i ++)
	{
		scanf("%d %d" , &s , &t);
		a[s][t] = 1; a[t][s] = 1;
	}
	//�ж��Ƿ����ŷ����·
	s = 0; start = 1;
	for (i = 1; i <= n; i ++)
	{
		num = 0;
		for (j = 1; j <= n; j ++)
			num += a[i][j];
		if (num % 2 == 1) {start = i; s ++;}
	}
	if ((s == 0) || (s == 2)) Euler(start);
	else printf("No Euler path\n");
	return 0;
}