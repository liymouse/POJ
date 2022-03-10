#include <stdio.h>
#include <vector>
using namespace std;

int main()
{
int w , s;
int n;
char name[65][20];
int b[65] = {0};
vector<int> res;
	
	scanf("%d" , &n);
	for (int i = 0; i < n; i ++)
	{
		scanf("%s" , name[i]);
	}
	scanf("%d,%d" , &w , &s);
	int k , i , num = n;
	i = w-1; k = 1;
	while (num)
	{
		while (b[i]) {i ++; if (i == n) i = 0;}
		if (k == s)
		{
			b[i] = 1;
			num --;
			res.push_back(i);
			k = 0;
		}
		i ++; k ++;
		if (i == n) i = 0;
	}
	for (int i = 0; i < n; i ++)
		printf("%s\n" , name[res[i]]);
	return 0;
}
