#include <stdio.h>
#include <string.h>

void get_next(char s[] , int next[])
{
int i , j , L;

	L = strlen(s);
	i = 0;
	next[0] = -1;
	j = -1;
	while (i < L-1)
	{
		if (j < 0 || s[i] == s[j]) { i ++; j ++; next[i] = j; }
		else j = next[j];
	}
}

//�Ż������next���麯��
//tΪ�Ӵ��� nextvalΪnext����
void get_nextval(char t[] , int nextval[])
{
int i , j , L;

	L = strlen(t);
	i = 0; nextval[0] = -1; j = -1;
	while (i < L-1)
	{
		if (j < 0 || t[i] == t[j])
		{
			i ++; j ++;
			if (t[i] != t[j]) nextval[i] = j;
			else nextval[i] = nextval[j];
		}
		else j = nextval[j];
	}
}

//sΪ���� �� tΪ�Ӵ� �� nextΪnext���飬 posΪ���ҿ�ʼλ�ã�����������posλhouѰ���Ӵ�
int KMP(char s[] , char t[] , int next[] , int pos)
{
int i , j , Ls , Lt;

	i = pos; j = 0;
	Ls = strlen(s);
	Lt = strlen(t);
	while (i < Ls && j < Lt)
	{
		if (j == -1 || s[i] == t[j]) {i ++; j ++;}
		else j = next[j];
	}
	if (j == Lt) return i - Lt;
	else return -1;
}

int main()
{
char smain[1000] = "acabaabaabcacaabc";
char sfind[1000] = "ababab";
int next[1000];
int pos;

	//get_next(sfind , next);
	get_nextval(sfind , next);
	pos = KMP(smain , sfind , next , 0);
	printf("%d" , pos);
	return 0;
}