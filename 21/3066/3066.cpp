#include <stdio.h>
#include <math.h>

int main()
{
	int m,p,a,b;
	while (scanf("%d%d%d%d",&m,&p,&a,&b)==4) 
	{
		double aa=0,bb=0;
		int n=m;
		if (b>0)
		{
			aa+=b;
			n-=b;
		}
		else
		if (b<0)
		{
			bb+=-a*b;
			n-=-a*b;
		}

		int t=n/(a+1);
		int xx=n%(a+1);
		aa+=t;
		bb+=a*t;
		if (xx>1)
		{
			bb+=pow(xx-1,p)+(xx-1);
		}
		double ansx=aa*pow(a,p/2)+bb/pow(a,p/2);
		printf("%.0lf\n",ansx);
	}
	return 0;
}

