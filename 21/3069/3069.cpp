#include <stdio.h>
#include <memory.h>

int main()
{
	int n,r;
	bool xx[2010];
	int x[1010];
	while (scanf("%d%d",&r,&n)==2 && r+n>0)
	{
		memset(x,0,sizeof(x));
		memset(xx,0,sizeof(xx));
		int i;
		int j;
		int cover=10000;
		int maxcover=0;
		for (i=1;i<=n;i++)
		{
			scanf("%d",&j);
			xx[j]=true;
		}		
		for (i=0;i<=1000;i++)
			if (xx[i])
			{
				x[++x[0]]=i;
			}
		int ans=0;
		for (i=1;i<=x[0];i++)
			if (x[i]!=-1)
			{
				ans++;
				j=i;
				while (j<=x[0] && x[j]-x[i]<=r) j++;
				j--;
				int t=j+1;
				while (t<=x[0] && x[t]-x[j]<=r) t++;
				t--;
				for (int p=i;p<=t;p++)
				{
					x[p]=-1;
				}
			}				
		printf("%d\n",ans);
	}
	return(0);
}
