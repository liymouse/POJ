#include  <stdio.h>
#include  <string.h>
	
char t[100];
int gl[100];
int len;

int goleft(int x)
{
	while (x>=0 && t[x]=='_') x--;
	if (x<0) return 100;
	if (t[x]=='.') return 100;
	if (t[x]=='|' || t[x]=='\\' || t[x]=='/') return 0;
}

int goright(int x)
{
	while (x<len && t[x]=='_') x++;
	if (x>=len) return 100;
	if (t[x]=='.') return 100;
	if (t[x]=='|' || t[x]=='\\' || t[x]=='/') return 0;
}

int proc(int x)
{
	int left,right;
	if (t[x]=='.') return 100;
	if (t[x]=='_') return 0;
	if (t[x]=='|')
	{
		left=goleft(x-1);
		right=goright(x+1);
		return (left+right)/2;
	}
	if (t[x]=='/') return (goleft(x-1));
	if (t[x]=='\\') return (goright(x+1));
	return 0;
}



int main()
{
	int i;
	while (scanf("%s",t)==1)
	{		
		len=strlen(t);		
		memset(gl,0,sizeof(gl));
		if (t[0]=='#') return 0;
		else
		{
			for (i=0; i<len; i++)
			{
				gl[i]=proc(i);	
			}
			int ans=0;
			for (i=0; i<len; i++)
			{
				ans+=gl[i];
			}
			printf("%d\n",ans/len);
		}
	}
	return 0;
}

