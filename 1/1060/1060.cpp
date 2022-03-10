#include <cstdio>
#include <string.h>
using namespace std;
int main()
{
    int f[2500],g[2500],h[2500],t[2500],df,dg,dh,T;
    scanf("%d",&T);
    while (T--){
          memset(f,0,sizeof(f));memset(g,0,sizeof(g));memset(h,0,sizeof(h));memset(t,0,sizeof(t));
          scanf("%d",&df);for (int i=df-1;i>=0;i--)scanf("%d",f+i);
          scanf("%d",&dg);for (int i=dg-1;i>=0;i--)scanf("%d",g+i);
          scanf("%d",&dh);for (int i=dh-1;i>=0;i--)scanf("%d",h+i);
          for (int i=dh-1;i>=0;i--)if (h[i]){dh=i+1;break;}
          for (int i=0;i<2500;i++)if (f[i])for (int j=i;j<2500;j++)t[j]=(t[j]^g[j-i]);
          for (int i=2499;i>=dh-1 && i>=0;i--)if (t[i])for (int j=0;j<dh;j++)t[j+i-dh+1]=(t[j+i-dh+1]^h[j]);
          for (int i=2499;i>=0;i--)
          if (t[i] || i==0){printf("%d",i+1);for (int j=i;j>=0;j--)printf(" %d",t[j]);printf("\n");break;}
    }
    return 0;
}
