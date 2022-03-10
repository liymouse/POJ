// 1182.cpp : 定义控制台应用程序的入口点。
//
#include <stdio.h>

int pre[50010],kind[50010];
int g1,g2;
int find(int x,int reme)
{
    int _x , h = x;
    int s , sign = 0 , s1;
    while(pre[h] != h)
    {
          sign = (sign + kind[h]) % 3;
          h = pre[h];
    }
    s = sign;
    while(pre[x]!=x)
    {
          _x = pre[x];
          pre[x] = h;
          s1 = kind[x];
          kind[x] = s;
          s = (3 - s1 + s) % 3;
          x = _x;
    }
    if (reme == 1) g1 = sign;
    else g2 = sign;
    return h;
}
int main()
{
    int m , n , i , d , x , y , num = 0;
	int _x , _y;
    scanf("%d %d" , &n , &m);
	for (i = 1; i <= n; i ++) { pre[i] = i; kind[i] = 0; }
	for (i = 0; i < m; i ++)
	{
		scanf("%d %d %d" , &d , &x , &y);
		if(x > n || y > n)   num++;
		//else if(d==2 && (x==y)) num++;
		else 
		{
			_x = find(x , 1); _y = find(y , 2);
			if(_x != _y) { pre[_x] = _y; kind[_x] = (2 + d - g1 + g2) % 3; }
			else if(d == 1 && g1 != g2)  num ++;
			else if(d == 2 && (3 - g2 + g1) % 3 != 1)  num ++;
		}
	}
	printf("%d\n",num);
	return 0;
}
    
