#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

struct node
{
	int a;	//mod 4 = 0
	int b;	//mod 4 = 1
	int c;	//mod 4 = 2
	int d;	//mod 4 = 3
};
queue<node>q;
int ta , tb , tc , td;
bool used[35][35][35][35];

void bfs()
{
	node tt,tmp;
	tmp = q.front();
	used[tmp.a][tmp.b][tmp.c][tmp.d] = 1;
	while(!q.empty())
	{
		tmp = q.front();
		q.pop();
		//rule 2
		if(tmp.a > 0 && tmp.c > 0)
		{
			tt.a = tmp.a - 1;
			tt.b = tmp.b + 1;
			tt.c = tmp.c - 1;
			tt.d = tmp.d + 1;
			if(!used[tt.a][tt.b][tt.c][tt.d])
			{
				used[tt.a][tt.b][tt.c][tt.d] = 1;
				q.push(tt);
			}
		}
		if(tmp.b > 0 && tmp.d > 0)
		{
			tt.a = tmp.a + 1;
			tt.b = tmp.b - 1;
			tt.c = tmp.c + 1;
			tt.d = tmp.d - 1;
			if(!used[tt.a][tt.b][tt.c][tt.d])
			{
				used[tt.a][tt.b][tt.c][tt.d] = 1;
				q.push(tt);
			}
		}
		//rule 3
		if(tmp.a > 0 && tmp.b > 0)
		{
			tt.a = tmp.a - 1;
			tt.b = tmp.b - 1;
			tt.c = tmp.c + 1;
			tt.d = tmp.d;
			if(!used[tt.a][tt.b][tt.c][tt.d])
			{
				used[tt.a][tt.b][tt.c][tt.d]=1;
				q.push(tt);
			}
		}
		if(tmp.b > 0 && tmp.c > 0)
		{
			tt.a = tmp.a;
			tt.b = tmp.b - 1;
			tt.c = tmp.c - 1;
			tt.d = tmp.d + 1;
			if(!used[tt.a][tt.b][tt.c][tt.d])
			{
				used[tt.a][tt.b][tt.c][tt.d]=1;
				q.push(tt);
			}
		}
		if(tmp.c > 0 && tmp.d > 0)
		{
			tt.a = tmp.a + 1;
			tt.b = tmp.b;
			tt.c = tmp.c - 1;
			tt.d = tmp.d - 1;
			if(!used[tt.a][tt.b][tt.c][tt.d])
			{
				used[tt.a][tt.b][tt.c][tt.d]=1;
				q.push(tt);
			}
		}
		if(tmp.a > 0 && tmp.d > 0)
		{
			tt.a = tmp.a - 1;
			tt.b = tmp.b + 1;
			tt.c = tmp.c;
			tt.d = tmp.d - 1;
			if(!used[tt.a][tt.b][tt.c][tt.d])
			{
				used[tt.a][tt.b][tt.c][tt.d]=1;
				q.push(tt);
			}
		}
		if(used[ta][tb][tc][td]==1)
			break;

	}
	if(used[ta][tb][tc][td]==1)
		printf("YES\n");
	else
		printf("NO\n");
}
int main()
{
	int cas,i,aa,bb,cc,dd;
	char str[35];
	scanf("%d",&cas);
	while(cas--)
	{
		memset(used,0,sizeof(used));
		scanf("%s",&str);
		aa=0;bb=0;cc=0;dd=0;
		ta=0;tb=0;tc=0;td=0;
		for(i=0;i<30;i++)
			if(str[i]=='*')
			{
				if(i%4==0)
					aa++;
				else if(i%4==1)
					bb++;
				else if(i%4==2)
					cc++;
				else if(i%4==3)
					dd++;
			}
		node tmp;
		tmp.a=aa;
		tmp.b=bb;
		tmp.c=cc;
		tmp.d=dd;
		while (!q.empty()) q.pop();
		q.push(tmp);
		scanf("%s",str);
		for(i=0;i<30;i++)
			if(str[i]=='*')
			{
				if(i%4==0)
					ta++;
				else if(i%4==1)
					tb++;
				else if(i%4==2)
					tc++;
				else if(i%4==3)
					td++;
			}
		bfs();
	}
	return 0;
}
