//PKU 2945
//统计复制dna的个数，采用字符串排序 nlogn
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

typedef struct
{
	char dna[22];
}DNAType;

int cmp(DNAType &x , DNAType &y)
{
	return strcmp(x.dna , y.dna) < 0;
}

int main()
{
DNAType a[20000];
int n , i , k , m;
int num[20000];

	while (scanf("%d %d" , &n , &m) == 2)
	{
		if (n == 0) break;
		for (i = 0; i < n; i ++) scanf("%s" , a[i].dna);
		sort(a , a + n , cmp);
		k = 0;
		memset(num , 0 , sizeof(num));
		for (i = 0; i < n-1; i ++)
		{
			if (strcmp(a[i].dna , a[i + 1].dna) == 0) k ++;
			else {num[k] ++; k = 0;}
		}
		num[k] ++;
		for (i = 0; i < n; i ++) printf("%d\n" , num[i]);
	}
	return 0;
}