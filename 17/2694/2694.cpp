#include <stdio.h>
#include <string.h>

int change_s(int c)
{
	if (c == 'C') return 0;
	else if (c == 'D') return 1;
	else if (c == 'H') return 2;
	else return 3;
}

int change_v(int c)
{
	if ((c >= '0') && (c <= '9')) return c - '0';
	else if (c == 'A') return 1;
	else if (c == 'X') return 10;
	else if (c == 'J') return 11;
	else if (c == 'Q') return 12;
	else return 13;
}

int main()
{
int t , i , j;
int shun , hua , dui , san , si;
char s[3];
struct kk{int v , s;}a[5] , x;

	//freopen("2694in.txt" , "r" , stdin);
	//freopen("2694out.txt" , "w" , stdout);
	scanf("%d" , &t);
	while (t --)
	{
		for (i = 0; i < 5; i ++)
		{
			scanf("%s" , s);
			strupr(s);
			a[i].s = change_s(s[0]);
			a[i].v = change_v(s[1]);
		}
		for (i = 0; i < 5; i ++)
			for (j = 1; j < 5 - i; j ++)
				if (a[j-1].v > a[j].v) {x = a[j-1]; a[j-1] = a[j]; a[j] = x;}
		hua = 1;
		for (i = 1; i < 5; i ++) if (a[i].s != a[0].s) {hua = 0; break;}
		shun = 1;
		for (i = 1; i < 5; i ++) if (a[i].v != a[i-1].v + 1) {shun = 0; break;}
		if ((a[0].v == 1) && (a[1].v == 10) && (a[2].v == 11) && (a[3].v == 12) && (a[4].v == 13)) shun = 1;
		si = 0;
		for (i = 3; i < 5; i ++) if ((a[i-3].v == a[i-2].v) && (a[i-2].v == a[i-1].v) && (a[i-1].v == a[i].v)) {si = 1; break;}
		san = 0;
		for (i = 2; i < 5; i ++) if ((a[i-2].v == a[i-1].v) && (a[i-1].v == a[i].v)) {san = 1; break;}
		dui = 0;
		for (i = 2; i < 4; i ++) if ((a[i-2].v != a[i-1].v) && (a[i-1].v == a[i].v) && (a[i].v != a[i+1].v)) dui ++;
		if ((a[2].v != a[3].v) && (a[3].v == a[4].v)) dui ++;
		if ((a[0].v == a[1].v) && (a[1].v != a[2].v)) dui ++;
		
		if (hua && shun) printf("1000\n");
		else if (si) printf("750\n");
		else if (san && dui) printf("500\n");
		else if (hua) printf("350\n");
		else if (shun) printf("250\n");
		else if (san) printf("200\n");
		else if (dui == 2) printf("100\n");
		else if (dui == 1) printf("50\n");
		else printf("0\n");
	}
	return 0;
}
