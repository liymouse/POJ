#include <stdio.h>

struct Stack{int num[100]; int top;}a;

void add()
{
int x , y;

	if (a.top < 1) printf("stack underflow\n");
	else
	{
		x = a.num[a.top]; y = a.num[a.top-1]; a.top --;
		a.num[a.top] = x + y;
	}
}

void sub()
{
int x , y;

	if (a.top < 1) printf("stack underflow\n");
	else
	{
		x = a.num[a.top]; y = a.num[a.top-1]; a.top --;
		a.num[a.top] = y - x;
	}
}

void mul()
{
int x , y;

	if (a.top < 1) printf("stack underflow\n");
	else
	{
		x = a.num[a.top]; y = a.num[a.top-1]; a.top --;
		a.num[a.top] = x * y;
	}
}

void div()
{
int x , y;

	if (a.top < 1) printf("stack underflow\n");
	else
	{
		x = a.num[a.top]; y = a.num[a.top-1]; a.top --;
		if (x == 0) printf("division by zero exception\n");
		else a.num[a.top] = y / x;
	}
}

void change(char s[])
{
int x , i;

	i = 0; x = 0;
	while (s[i] != 0)
	{
		switch(s[i])
		{
			case 'M' : x += 1000; break;
			case 'D' : x += 500; break;
			case 'L' : x += 50; break;
			case 'V' : x += 5; break;
			case 'C' : 
				if (s[i+1] == 'M') {x += 900; i ++;}
				else if (s[i+1] == 'D') {x += 400; i ++;}
					else x += 100;
				break;
			case 'X' :
				if (s[i+1] == 'C') {x += 90; i ++;}
				else if (s[i+1] == 'L') {x += 40; i ++;}
					else x += 10;
				break;
			case 'I' :
				if (s[i+1] == 'X') {x += 9; i ++;}
				else if (s[i+1] == 'V') {x += 4; i ++;}
					else x ++;
				break;
		}
		i ++;
	}
	a.top ++;
	a.num[a.top] = x;
}

void exchange(int x)
{
char s[20];
int i , t;

	i = 0;
	while (x >= 1000) {s[i ++] = 'M'; x -= 1000;}
	t = x / 100; x %= 100;
	switch (t)
	{
		case 1 : s[i ++] = 'C'; break;
		case 2 : s[i ++] = 'C'; s[i ++] = 'C'; break;
		case 3 : s[i ++] = 'C'; s[i ++] = 'C'; s[i ++] = 'C'; break;
		case 4 : s[i ++] = 'C'; s[i ++] = 'D'; break;
		case 5 : s[i ++] = 'D'; break;
		case 6 : s[i ++] = 'D'; s[i ++] = 'C'; break;
		case 7 : s[i ++] = 'D'; s[i ++] = 'C'; s[i ++] = 'C'; break;
		case 8 : s[i ++] = 'D'; s[i ++] = 'C'; s[i ++] = 'C'; s[i ++] = 'C'; break;
		case 9 : s[i ++] = 'C'; s[i ++] = 'M'; break;
	}
	t = x / 10; x %= 10;
	switch (t)
	{
		case 1 : s[i ++] = 'X'; break;
		case 2 : s[i ++] = 'X'; s[i ++] = 'X'; break;
		case 3 : s[i ++] = 'X'; s[i ++] = 'X'; s[i ++] = 'X'; break;
		case 4 : s[i ++] = 'X'; s[i ++] = 'L'; break;
		case 5 : s[i ++] = 'L'; break;
		case 6 : s[i ++] = 'L'; s[i ++] = 'X'; break;
		case 7 : s[i ++] = 'L'; s[i ++] = 'X'; s[i ++] = 'X'; break;
		case 8 : s[i ++] = 'L'; s[i ++] = 'X'; s[i ++] = 'X'; s[i ++] = 'X'; break;
		case 9 : s[i ++] = 'X'; s[i ++] = 'C'; break;
	}
	switch (x)
	{
		case 1 : s[i ++] = 'I'; break;
		case 2 : s[i ++] = 'I'; s[i ++] = 'I'; break;
		case 3 : s[i ++] = 'I'; s[i ++] = 'I'; s[i ++] = 'I'; break;
		case 4 : s[i ++] = 'I'; s[i ++] = 'V'; break;
		case 5 : s[i ++] = 'V'; break;
		case 6 : s[i ++] = 'V'; s[i ++] = 'I'; break;
		case 7 : s[i ++] = 'V'; s[i ++] = 'I'; s[i ++] = 'I'; break;
		case 8 : s[i ++] = 'V'; s[i ++] = 'I'; s[i ++] = 'I'; s[i ++] = 'I'; break;
		case 9 : s[i ++] = 'I'; s[i ++] = 'X'; break;
	}
	s[i] = 0;
	printf("%s\n" , s);
}	

void pri()
{

	if (a.top == -1) printf("stack underflow\n");
	else
	{
		if ((a.num[a.top] <= 0) || (a.num[a.top] > 4999)) printf("out of range exception\n");
		else exchange(a.num[a.top]);
	}
}

int main()
{
char s[20];

	a.top = -1;
	while (scanf("%s" , s) == 1)
	{
		switch(s[0])
		{
			case '+' : add(); break;
			case '-' : sub(); break;
			case '*' : mul(); break;
			case '/' : div(); break;
			case '=' : pri(); break;
			default : change(s); break;
		}
	}
	return 0;
}