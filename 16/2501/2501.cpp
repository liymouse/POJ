#include <stdio.h>

int main()
{
int h , m , s , v , speed;
double dist , last , now;
char c;
char st[10];

    dist = 0; last = 0; now = 0; speed = 0;
    while (scanf("%s" , st) == 1)
    {
		h = (st[0]-'0') * 10 + st[1]-'0';
		m = (st[3]-'0') * 10 + st[4]-'0';
		s = (st[6]-'0') * 10 + st[7]-'0';
		now = h + m*1.0 / 60 + s*1.0 / 3600;
        dist += (now - last) * speed;
        scanf("%c" , &c);
        if (c == ' ') 
        {
            scanf("%d" , &v);
            speed = v;
        }
        else printf("%s %.2lf km\n" , st , dist);
        last = now;
    }
    return 0;
}
