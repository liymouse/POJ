/*
1.把181440个状态转成181440个32int(每个数字用3位储存，8为000，最后用4位储存x的位置，整数符号为为0)
2.快排,升序
3.读入
4.二分查找标号
5.广搜
6.输出路径
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

struct {
	int datanum , from , fang;
}sersta[181450];
int p[4] = {-3 , 1 , -1 , 3};
int sta[181450] = {0} , totnum;
bool have[181450] = {0};
int a[9] , b[9];
int now;

bool cmp(int &x , int &y)
{
	return x < y;
}

inline int change(int position)
{
int x , i;

	x = 0;
	for (i = 0; i < 8; i ++)
	{
		if (a[i] < 8) x += a[i];
		x = x << 3;
	}
	x = x << 1;
	x += position;
	return x;
}

void prepare(int k)
{
int i , j , s;

	if (k == 8)
	{
		s = 0;
		for (i = 1; i < 8; i ++) for (j = 0; j < i; j ++) if (a[j] < a[i]) s ++;
		if (s % 2 == 0)
		{
			for (i = 1; i <= 9; i ++)
			{
				sta[totnum] = change(i);
				totnum ++;
			}
		}
		return;
	}
	for (i = 1; i <= 8; i ++)
		if (b[i] == 0)
		{
			a[k] = i; b[i] = 1;
			prepare(k + 1);
			a[k] = 0; b[i] = 0;
		}
}

int find(int x)
{
int p , q , m;

	p = 0; q = 181439;
	while (1)
	{
		m = (p + q) / 2;
		if (x > sta[m]) p = m + 1;
		else if (x < sta[m]) q = m - 1;
		else break;
	}
	return m;
}

void search()
{
int i , j , n , x , nsta , npos , y;

	n = 0;
	while (1)
	{
		nsta = sta[sersta[n].datanum];
		npos = 15 & nsta;
		for (i = 0; i < 4; i ++)
		{
			if ((i == 0) && (npos < 4)) continue;
			if ((i == 3) && (npos > 6)) continue;
			if ((i == 1) && (npos % 3 == 0)) continue;
			if ((i == 2) && (npos % 3 == 1)) continue;
			if ((i == 1) || (i == 2))
				x = (nsta & 268435440) + npos + p[i];//&111 111 111 111 111 111 111 111 0000
			else
			{
				y = 234881024; //111 000 000 000 000 000 000 000 0000
				for (j = 0; j < 8; j ++)
				{
					a[j] = nsta & y;
					a[j] = a[j] >> (25 - j * 3);
					if (a[j] == 0) a[j] = 8;
					y /= 8;
				}
				for (j = 8; j >= npos; j --)
					a[j] = a[j-1];
				a[npos-1] = 0;
				y = a[npos-1]; a[npos-1] = a[npos-1 + p[i]]; a[npos - 1 + p[i]] = y;
				for (j = 0; j < 9; j ++) if (a[j] == 0) break;
				while (j < 8) {a[j] = a[j + 1]; j ++;}
				x = change(npos + p[i]);
			}
			y = find(x);
			if (have[y] == 0)
			{
				have[y] = 1;
				now ++;
				sersta[now].datanum = y;
				sersta[now].from = n;
				sersta[now].fang = i;
				if (x == 43826057) return;
			}
		}
		n ++;
	}
}

int main()
{
int i , j , n , k , pos , x;
char s[500];

	totnum = 0;
	memset(b , 0 , sizeof(b));
	prepare(0);
	sort(sta , sta + totnum , cmp);
    gets(s); 
    n = 0;
    for (i = 0; i < strlen(s); i ++)
        if ((s[i] <= '9') && (s[i] >= '0')) a[n++] = s[i] - '0';
        else if (s[i] == 'x') pos = n + 1;
	k = 0;
	for (i = 1; i < 8; i ++) for (j = 0; j < i; j ++) if (a[j] < a[i]) k ++;
	if (k % 2 == 1) printf("unsolvable\n");
	else
	{
		j = change(pos);
		if (j == 43826057) {printf("\n"); return 0;}
		x = find(j);
		have[x] = 1;
		sersta[0].datanum = x;
		sersta[0].from = -1;
		now = 0;
		search();
		n = 0;
		while (sersta[now].from != -1)
		{
			switch(sersta[now].fang)
			{
				case 0 : s[n ++] = 'u'; break;
				case 1 : s[n ++] = 'r'; break;
				case 2 : s[n ++] = 'l'; break;
				case 3 : s[n ++] = 'd'; break;
			}
			now = sersta[now].from;
		}
		for (i = n - 1; i >= 0; i --) printf("%c" , s[i]);
		printf("\n");
	}
    return 0;
}    
