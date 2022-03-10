#include <iostream.h>

int main()
{
int die[1000] , s[101] , go[101];
int player[6] , b[6];
int n , tot , i , j , now , done;

    tot = 0;
    while (cin >> die[tot ++])
        if (die[tot - 1] == 0) break;
    tot --;
    while (cin >> n)
    {
        if (n == 0) break;
		for (i = 1; i <= 100; i ++) {go[i] = i; s[i] = 0;}
		for (i = 0; i < n; i ++) player[i] = 0;
        while (cin >> i >> j)
        {
            if ((i == 0) && (j == 0)) break;
            go[i] = j;
        }
        while (cin >> i)
        {
            if (i == 0) break;
            if (i > 0) s[i] = 1;
            else {i = -i; s[i] = -1;}
        }
        now = 0; done = 0;
        while (1)
        {
            for (i = 0; i < n; i ++)
			{
				if (b[i] != -1)
				do
				{
					if (player[i] + die[now] <= 100)
					{
						player[i] += die[now];
						if (player[i] == 100)
						{
							cout << i + 1 << endl;
							done = 1;
							break;
						}
						now ++;
						player[i] = go[player[i]];
						b[i] = s[player[i]];
					}
				}while ((b[i] == 1) && (done == 0));
				else b[i] = 0;
				if (done) break;
			}
            if (done) break;   
        }
    }   
    return 0;
}    
