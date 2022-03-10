#include <cstdio>
#include <sstream>
#include <string>
using namespace std;

int main()
{
int t , i , n , x , b , c , d , j;
int a[10000] , num[10] , tot;
char name[51] , s[102];
char ch;

	scanf("%d\n" , &t);
	while (t --)
	{
		gets(name);
		memset(a , 0 , sizeof(a));
		scanf("%d\n" , &n);
		for (i = 0; i < n; i ++)
		{
			gets(s);
			if (s[0] == '+')
			{
				string line(s);
				istringstream input(line);
				input>>ch>>b>>c>>d;
				for (j = b; j <= c; j += d) if (a[j] != -1) a[j] = 1;
			}
			else if (s[0] == '-')
			{
				string line(s);
				istringstream input(line);
				input>>ch>>b>>c>>d;
				for (j = b; j <= c; j += d) a[j] = -1;
			}
			else
			{
				string line(s);
				istringstream input(line);
				input>>x;
				if (a[x] != -1) a[x] = 1;
			}
		}
		tot = 0;
		memset(num , 0 , sizeof(num));
		for (i = 1; i < 10000; i ++) 
			if (a[i] == 1)
			{
				tot ++; x = i;
				while (x > 0) {num[x % 10] ++; x /= 10;}
			}
		printf("%s\n" , name);
		if (tot != 1) printf("%d addresses\n" , tot);
		else printf("%d address\n" , tot);
		tot = 0;
		for (i = 0; i < 10; i ++)
		{
			printf("Make %d digit %d\n" , num[i] , i);
			tot += num[i];
		}
		if (tot != 1) printf("In total %d digits\n" ,tot);
		else printf("In total %d digit\n" , tot);
	}
	return 0;
}