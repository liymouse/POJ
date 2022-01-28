//都按照非降排序 
#include <stdio.h>

void bubble(int a[] , int n)
{
int i , j , k;

    for (i = 0; i < n; i ++)
        for (j = 1; j < n - i; j ++)
            if (a[j-1] > a[j]) {k = a[j-1]; a[j-1] = a[j]; a[j] = k;} //按降序排列改为a[j-1] < a[j] 
}

void quick(int a[] , int s , int t)
{
int i , j , x , y;

    i = s; j = t; x = a[(i+j)/2];
    while (i <= j)
    {
        while (a[i] < x) i ++;     //按降序排列改为 a[i] > x
        while (a[j] > x) j --;     //按降序排列改为 a[j] < x
        if (i <= j)
        {
            y = a[i]; a[i] = a[j]; a[j] = y;
            i ++; j --;
        }
    }
    if (i < t) quick(a , i , t);
    if (s < j) quick(a , s , j);
}

void shift(int a[] , int i , int m) //调整为大根堆，i要调整的节点编号，m堆的节点个数 
{
int k , t;

    t = a[i]; k = 2 * i + 1; //下标以0开头的完全二叉树节点i左孩子为i*2+1右孩子为i*2+2 
    while (k < m)
    {
        if ((k < m - 1) && (a[k] < a[k+1])) k ++;
        if (t < a[k]) {a[i] = a[k]; i = k; k = 2 * i + 1;}
        else break;
	}
    a[i] = t;
}

void heap(int a[] , int n)
{
int i , k;

	for (i = n/2-1; i >= 0; i --) shift(a , i , n);  // 建堆 
    for (i = n-1; i >= 1; i --)  // 排序 
    {
		k = a[0]; a[0] = a[i]; a[i] = k;
		shift(a , 0 , i);
    }
}

void merge(int a[] , int temp[] , int Lpos , int Rpos , int RightEnd)
{
int i , LeftEnd , num , tmppos;

	LeftEnd = Rpos - 1;
	tmppos = Lpos;
	num = RightEnd - Lpos + 1;
	while (Lpos <= LeftEnd && Rpos <= RightEnd)
		if (a[Lpos] <= a[Rpos]) temp[tmppos ++] = a[Lpos ++];
		else temp[tmppos ++] = a[Rpos ++];
	while (Lpos <= LeftEnd) temp[tmppos ++] = a[Lpos ++];
	while (Rpos <= RightEnd) temp[tmppos ++] = a[Rpos ++];
	for (i = 0; i < num; i ++)
	{
		a[RightEnd] = temp[RightEnd];
		RightEnd --;
	}
}

void msort(int a[] , int temp[] , int L , int r)
{
int c;

	if (L < r)
	{
		c = (L + r) / 2;
		msort(a , temp , L , c);
		msort(a , temp , c + 1 , r);
		merge(a , temp , L , c + 1 , r);
	}
}

void mergesort(int a[] , int n)
{
int temp[10000];

	msort(a , temp , 0 , n - 1);
}

int main()
{
int a[10000] , n , i;

    printf("Please input N : ");
    scanf("%d" , &n);
    for (i = 0; i < n; i ++) scanf("%d" , &a[i]);
    //bubble(a , n); //冒泡排序，O(n^2) 
    //quick(a , 0 , n-1); //快速排序, O(nlogn) ，0为数组起始下标，n-1为数组末下标
    heap(a , n); //堆排序，O(nlogn) 
	//mergesort(a , n); //归并排序
    for (i = 0; i < n; i ++) printf("%d " , a[i]);
    getchar(); getchar();
    return 0;
}
