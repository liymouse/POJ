#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

struct kk{char first[100] , change[100];}a[1000];
int b[1000];

bool cmps(kk &x , kk &y)
{
	return strcmp(x.change , y.change) < 0;
}

bool cmpn(int &x , int &y)
{
	return x < y;
}

int main()
{
int n , n1 , n2 , L , bo , i , x , y;
char s[100];
int num[1000];

	n = 0; memset(num , 0 , sizeof(num));
	n1 = 0; n2 = 0;
	while (scanf("%s" , s) == 1)
	{
		if (s[0] == '.') break;
		L = strlen(s); bo = 0;
		if (s[L-1] == '.') bo = 1;
		L --; s[L] = 0; n ++;
		if (((s[0] >= '0') && (s[0] <= '9')) || (s[0] == '-'))
		{
			num[n-1] = 1;
			b[n2] = 0;
			if (s[0] == '-')
			{
				for (i = 1; i < L; i ++) b[n2] = b[n2] * 10 + s[i] - '0';
				b[n2] = -b[n2];
			}
			else for (i = 0; i < L; i ++) b[n2] = b[n2] * 10 + s[i] - '0';
			n2 ++;
		}
		else
		{
			strcpy(a[n1].first , s);
			strcpy(a[n1].change , s);
			strlwr(a[n1].change);
			n1 ++;
		}
		if (bo)
		{
			sort(a , a + n1 , cmps);
			sort(b , b + n2 , cmpn);
			x = 0; y = 0;
			for (i = 0; i < n-1; i ++)
				if (num[i] == 0) printf("%s, " , a[x ++].first);
				else printf("%d, " , b[y ++]);
			if (num[n-1] == 0) printf("%s.\n" , a[x].first);
			else printf("%d.\n" , b[y]);
			n = 0; n1 = 0; n2 = 0;
			memset(num , 0 , sizeof(num));
		}
	}
	return 0;
} 