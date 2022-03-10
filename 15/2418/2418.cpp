#include <stdio.h>
#include <string>
#include <map>
using namespace std;

map<string , int> a;

int main()
{
char s[40];
int n = 0;

	while (scanf("%s" , s) == 1)
	{
		if (a.find(s) != a.end()) a[s] ++;
		else a.insert(pair<string,int>(s,1));
		n ++;
	}
	for (map<string , int>::iterator i = a.begin(); i != a.end(); i ++)
	{
		printf("%s %lf.4\n" , i->first , i->second * 100.0 / (double)n);
	}
}