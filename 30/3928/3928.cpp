#include <stdio.h>
#include <string.h>

typedef long long i64d;
int pre[100010] , after[100010];

void merge(int a[] , int Lpos , int Rpos , int RightEnd)
{
    int temp[20000];

	int LeftEnd = Rpos - 1;
	int tmppos = Lpos;
	int num = RightEnd - Lpos + 1;
    int tmppre = 0 , tmpafter = 0;
	while (Lpos <= LeftEnd && Rpos <= RightEnd)
		if (a[Lpos] <= a[Rpos])
        {
            tmppre ++;
            //pre[a[Rpos]] ++;
            after[a[Lpos]] += tmpafter;
            temp[tmppos ++] = a[Lpos ++];
        }
		else
        {
            tmpafter ++;
            //after[a[Lpos]] ++;
            pre[a[Rpos]] += tmppre;
            temp[tmppos ++] = a[Rpos ++];
        }
    while (Lpos <= LeftEnd)
    {
        after[a[Lpos]] += tmpafter;
        temp[tmppos ++] = a[Lpos ++]; 
        //if (Lpos <= LeftEnd) after[a[Lpos]] += after[a[Lpos-1]];
    }
    while (Rpos <= RightEnd)
    {
        pre[a[Rpos]] += tmppre;
        temp[tmppos ++] = a[Rpos ++];
        //if (Rpos <= RightEnd) pre[a[Rpos]] += pre[a[Rpos-1]] + 1;
    }
	for (int i = 0; i < num; i ++)
    {
        a[RightEnd] = temp[RightEnd];
        RightEnd --;
    }
}

void mergesort(int a[] , int L , int r)
{
    if (L >= r) return;
    int c = (L + r) / 2;
	mergesort(a , L , c);
	mergesort(a , c + 1 , r);
	merge(a , L , c + 1 , r);
}

int main()
{
    int ca;
    scanf("%d" , &ca);
    while (ca --)
    {
        int n;
        int a[20000] , b[20000];
        scanf("%d" , &n);
        for (int i = 0; i < n; i ++) {scanf("%d" , &a[i]); b[i] = a[i];}
        memset(after , 0 , sizeof(after));
        memset(pre , 0 , sizeof(pre));
        mergesort(b , 0 , n-1);
        i64d res = 0;
        for (int i = 0; i < n; i ++)
        {
            //small -> big
            res += (i64d)pre[a[i]] * (i64d)(n-i-1-after[a[i]]);
            //big -> small
            res += (i64d)(i-pre[a[i]]) * (i64d)after[a[i]];
        }
        printf("%lld\n" , res);
    }
    return 0;
}
