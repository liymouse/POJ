#include <iostream>
#include <string>
using namespace std;

int f[20] = {1,1,2,5,14,42,132,429,1430,4862,16796,58786,208012,742900,2674440,
9694845,35357670,129644790,477638700,1767263190};

string print(int num)
{
string s[100];
int L , R , i , j , p , q , x , y;

	if (num == 1) return "X";
	else if (num == 2) return "X(X)";
		else if (num == 3) return "(X)X";
	i = 1;
	while (num > f[i]) {num -= f[i]; i ++;}
	for (j = 0; j < i; j ++)
	{
		if (num > f[j] * f[i - j - 1]) num -= f[j] * f[i-j-1];
		else break;
	}
	L = j; R = i - j - 1;
	q = num % f[R]; if (q == 0) q = f[R];
	p = num / f[R]; if (q < f[R]) p ++;
	x = 0; y = 0;
	for (j = 1; j < L; j ++) x += f[j];
	for (j = 1; j < R; j ++) y += f[j];
	if (q == 0) p --;
	if (L == 0) return "X(" + print(y + q) + ")";
	else if (R == 0) return "(" + print(x + p) + ")X";
		else return "(" + print(x + p) + ")X(" + print(y + q) + ")";
}

int main()
{
int n;
string s[100];

	//freopen("1095.out" , "w" , stdout);
	while (cin >> n)
	{
		if (n == 0) break;
		cout << print(n) << endl;
	}
	return 0;
}