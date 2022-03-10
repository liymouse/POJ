#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <stdio.h>
using namespace std;

int main()
{
	//string str;
	char str[200];
	vector<string> a[1010];
	int line = 0;
	int maxnum = 0;
	//while (getline(cin , str))
	while (gets(str) != NULL)
	{
		stringstream ss((string)str);
		string str1;
		while (ss >> str1)
		{
			a[line].push_back(str1);
		}
		maxnum = max(maxnum , (int)a[line].size());
		line ++;
	}
	for (int i = 0; i < maxnum; i ++)
	{
		int L = 0;
		for (int j = 0; j < line; j ++)
			if (i < a[j].size()) L = max(L , (int)a[j][i].length());
		for (int j = 0; j < line; j ++)
			if (i < a[j].size())
			{
				int add = L - a[j][i].length();
				while (add --) a[j][i] += " ";
			}
	}
	for (int i = 0; i < line; i ++)
	{
		if (a[i].size() > 0)
		{
			printf("%s" , a[i][0].c_str());
			for (int j = 1; j < a[i].size(); j ++) printf(" %s" , a[i][j].c_str());
		}
		printf("\n");
	}
	return 0;
}