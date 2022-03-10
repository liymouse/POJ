#include <stdio.h>

__int64 a[1000000];

int main()
{
   __int64 i;
   int j,n,x,y;
   for (i=0;i<500000;i++)
   {
      a[2*i]=i*(i+1);
      a[2*i+1]=(i+1)*(i+1);
   }
   scanf("%d",&n);
   while (n--) 
   {
      scanf("%d%d",&x,&y);
      for (j=0;a[j]<y-x;j++);
      printf("%d\n",j);
   }
   return 0;
}


