#include <stdio.h>
#include <string.h>
#define MAXN 101
int n,len1,len2;
char st1[MAXN],st2[MAXN];


int compare(char a,char b)
{
    if (a==b) return 5;
    else 
      switch (a) 
       {
         case 'A' :  switch (b) 
                     {
                      case 'T' : return -1;
                      case 'G' : return -2;
                      case 'C' : return -1;
                      case ' ' : return -3;
                     }     
         case 'T' :  switch (b) 
                     {
                         case 'A': return -1;
                         case 'G': return -2;
                         case 'C': return -2;
                         case ' ': return -1;
                     }       
         case 'G' :  switch (b)
                     {
                         case 'A': return -2;
                         case 'T': return -2;
                         case 'C': return -3;
                         case ' ': return -2;
                     }
         case 'C' :  switch (b)
                     {
                         case 'A': return -1;
                         case 'T': return -2;
                         case 'G': return -3;
                         case ' ': return -4;
                     }
      }
     return 0;
}                                   
            

int main()
{
    int i,j,t1,t2,t3,q,max;
    long ans;
    long f[MAXN][MAXN];
    FILE *fp;

    fp=fopen("1080.in","r");

    scanf("%d",&n);/*  fscanf(fp,"%d",&n);*/
    for (q=0;q<n;q++)
    {
	scanf("%d%s",&len1,st1);
	scanf("%d%s",&len2,st2);
	memset(f,0,sizeof(f));
       /*	fscanf(fp,"%d%s",&len1,st1);
	fscanf(fp,"%d%s",&len2,st2);*/

	for (j=0;j<len2;j++)
	 for (i=j;i<len2;i++)
	  f[len1][j]+=compare(st2[i],' ');

	for (i=0;i<len1;i++)
         for (j=i;j<len1;j++) 
	  f[i][len2]+=compare(st1[j],' ');
          
          
        for (i=len1-1;i>=0;i--)
         for (j=len2-1;j>=0;j--)
          {
              t1=f[i+1][j+1]+compare(st1[i],st2[j]);
              t2=f[i][j+1]+compare(st2[j],' ');
              if (t2<t1) t2=t1;
              t3=f[i+1][j]+compare(st1[i],' ');
              if (t3<t2) t3=t2;
              f[i][j]=t3;
          }       
	 
        printf("%ld\n",f[0][0]);
    }
    return 0;
}           

