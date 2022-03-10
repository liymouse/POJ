#include <stdio.h>
#include <string.h>

int father[26];

int getfather(int x)
{
int f;

	if (father[x] == x) return x;
	else
	{
		f = getfather(father[x]);
		father[x] = f;
		return f;
	}
}

int main()
{
int t , n , p[2];
char s[1001];
int i , j , bo;
int a[26][26] , ind , outd , b[26] , L , tot , x;

	scanf("%d" , &t);
	while (t --)
	{
		scanf("%d" , &n);
		memset(a , 0 , sizeof(a));
		memset(b , 0 , sizeof(b));
		for (i = 0; i < n; i ++) 
		{
			scanf("%s" , s);
			L = strlen(s);
			b[s[0] - 'a'] = 1; b[s[L-1] - 'a'] = 1;
			a[s[0] - 'a'][s[L-1] - 'a'] ++;
		}
		for (i = 0; i < 26; i ++) father[i] = i;
		for (i = 0; i < 26; i ++)
			for (j = i + 1; j < 26; j ++)
				if ((a[i][j] > 0) || (a[j][i] > 0)) father[getfather(i)] = getfather(j);
		bo = 0;
		for (i = 0; i < 26; i ++) 
			if (b[i]) {x = getfather(i); break;}
		for (i = 0; i < 26; i ++) if ((b[i]) && (getfather(i) != x)) {bo = 1; break;}
		if (bo == 0)
		{
			tot = 0;
			for (i = 0; i < 26; i ++)
			{
				ind = 0; outd = 0;
				for (j = 0; j < 26; j ++)
				{
					if (a[i][j] > 0) outd += a[i][j];
					if (a[j][i] > 0) ind += a[j][i];
				}
				if (ind != outd)
				{
					if (ind > outd) p[tot] = ind - outd;
					else p[tot] = outd - ind;
					if (p[tot] != 1) bo = 1;
					tot ++;
				}
				if (tot > 2) {bo = 1; break;}
			}
			if ((tot != 0) && (tot != 2)) bo = 1;	
		}
		if (bo) printf("The door cannot be opened.\n");
		else printf("Ordering is possible.\n");
	}
	return 0;
}