//http://www.asahi-net.or.jp/~kc2h-msm/excel/excel002.htm
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define NUM 1000
const int maxlength=3000;
class bigint {
public:
	int oper,length,a[maxlength];
	bigint(int=0);
	~bigint();
	int max(int a,int b);
	void check();
	void operator=(bigint m);
	void operator=(int m);
	void operator=(char *s);
	bool operator<(bigint m);
	bool operator<=(bigint m);
	bool operator>(bigint m);
	bool operator>=(bigint m);
	bool operator==(bigint m);
	bool operator!=(bigint m);
	bigint operator-();
	bigint operator+(bigint m);
	void operator+=(bigint m);
	bigint operator-(bigint m);
	void operator-=(bigint m);
	bigint operator*(bigint m);
	bigint operator*(int m);
	void operator*=(bigint m);
	void operator*=(int m);
	bigint operator/(bigint m);
	bigint operator/(int m);
	void operator/=(bigint m);
	void operator/=(int m);
	bigint operator%(bigint m);
	bigint operator%(int m);
	void operator%=(bigint m);
	void operator%=(int m);
};

bigint abs(bigint m);

bool read(bigint &m);
void write(bigint m);
void swrite(char *s,bigint m);
void writeln(bigint m);
bigint sqr(bigint m);
bigint sqrt(bigint m);
bigint gcd(bigint a,bigint b);
bigint lcm(bigint a,bigint b);

int bigint::max(int a,int b)
{
	return (a>b)?a:b;
}

bigint::bigint(int v)
{
	(*this)=v;
	this->check();
}

bigint::~bigint()
{

}

void bigint::check()
{
	for (;length>0 && a[length]==0;length--);
	if (length==0)
		oper=1;
}

void bigint::operator=(bigint m)
{
	oper=m.oper;
	length=m.length;
	memcpy(a,m.a,maxlength*sizeof(int));
	this->check();
}


int iabs(int x)
{
	return x>0?x:-x;
}


void bigint::operator=(int m)
{
	oper=(m>0)?1:-1;
	m=iabs(m);
	memset(a,0,maxlength*sizeof(int));
	for (length=0;m>0;m=m/10000)
		a[++length]=m%10000;
	this->check();
}

void bigint::operator=(char *s)
{
int i,L;

	(*this)=0;
	if (s[0]=='-' || s[0]=='+')
	{
		if (s[0]=='-')
			oper=-1;
		L=strlen(s);
		for (i=0;i<L;i++)
			s[i]=s[i+1];
	}
	L=strlen(s);
	length=(L+3)/4;
	for (i=0;i<L;i++)
		a[(L-i+3)/4]=a[(L-i+3)/4]*10+(s[i]-48);
	this->check();
}

bool bigint::operator<(bigint m)
{
	if (oper!=m.oper)
		return oper<m.oper;
	if (length!=m.length)
		return oper*length<m.length*oper;
	for (int i=length;i>=1;i--)
		if (a[i]!=m.a[i])
			return a[i]*oper<m.a[i]*oper;
	return false;
}

bool bigint::operator<=(bigint m)
{
	return !(m<(*this));
}

bool bigint::operator>(bigint m)
{
	return m<(*this);
}

bool bigint::operator>=(bigint m)
{
	return !((*this)<m);
}

bool bigint::operator==(bigint m)
{
	return (!((*this)<m)) && (!(m<(*this)));
}

bool bigint::operator!=(bigint m)
{
	return ((*this)<m) || (m<(*this));
}

bigint bigint::operator-()
{
bigint c=(*this);

	c.oper=-c.oper;
	c.check();
	return c;
}

bigint abs(bigint m)
{
bigint c=m;

	c.oper=iabs(c.oper);
	c.check();
	return c;
}

bigint bigint::operator+(bigint m)
{
	if (m.length==0)
		return (*this);
	if (length==0)
		return m;
	if (oper==m.oper)
	{
		bigint c;

		c.oper=oper;
		c.length=max(length,m.length)+1;
		for (int i=1,temp=0;i<=c.length;i++)
			c.a[i]=(temp=(temp/10000+a[i]+m.a[i]))%10000;
		c.check();
		return c;
	}
	return (*this)-(-m);
}

bigint bigint::operator-(bigint m)
{
	if (m.length==0)
		return (*this);
	if (length==0)
		return (-m);
	if (oper==m.oper)
	{
		bigint c;

		if (abs(*this)>=abs(m))
		{
			c.oper=oper;
			c.length=length;
			for (int i=1,temp=0;i<=length;i++)
				c.a[i]=((temp=(-int(temp<0)+a[i]-m.a[i]))+10000)%10000;
			c.check();
			return c;
		}
		return -(m-(*this));
	}
	return (*this)+(-m);

}

bool read(bigint &m)
{
char s[maxlength*4+10];

	if (scanf("%s",s)==-1)
		return false;
	for (int i=0;s[i];i++)
		if (!(s[i]>='0' && s[i]<='9' || (s[i]=='+' || s[i]=='-') && i==0))
			return false;
	m=s;
	return true;
}

void swrite(char *s,bigint m)
{
int L=0;

	if (m.oper==-1)
		s[L++]='-';
	sprintf(s+L,"%d",m.a[m.length]);
	for (;s[L]!=0;L++);
	for (int i=m.length-1;i>=1;i--)
	{
		sprintf(s+L,"%04d",m.a[i]);
		L+=4;
	}
	s[L]=0;
}

void write(bigint m)
{
	if (m.oper==-1)
		printf("-");
	printf("%d",m.a[m.length]);
	for (int i=m.length-1;i>=1;i--)
		printf("%04d",m.a[i]);
}

void writeln(bigint m)
{
	write(m);
	printf("\n");
}

bigint bigint::operator*(bigint m)
{
	bigint c;

	c.oper=oper*m.oper;
	c.length=length+m.length;
	for (int i=1;i<=m.length;i++)
	{
		int number=m.a[i],j,temp=0;
		for (j=1;j<=length;j++)
			c.a[i+j-1]+=number*a[j];
		if (i%10==0 || i==m.length)
			for (j=1;j<=c.length;j++)
				c.a[j]=(temp=(temp/10000)+c.a[j])%10000;
	}
	c.check();
	return c;
}

bigint bigint::operator*(int m)
{
	if (m<0)
		return -((*this)*(-m));
	if (m>10000)
		return (*this)*bigint(m);
	bigint c;

	c.length=length+1;
	c.oper=oper;
	int t=0;
	for (int i=1;i<=c.length;i++)
		c.a[i]=(t=(t/10000+a[i]*m))%10000;
	c.check();
	return c;
}

bigint bigint::operator/(bigint m)
{
	if (m.length==0)
	{
		printf("Division by zero.\n");
		exit(0);
	}
	if (abs(*this)<abs(m))
		return 0;
	bigint c,left;

	c.oper=oper/m.oper;
	m.oper=1;
	c.length=length-m.length+1;
	left.length=m.length-1;
	memcpy(left.a+1,a+length-left.length+1,left.length*sizeof(int));
	for (int i=c.length;i>=1;i--)
	{
		left=left*10000+a[i];
		int head=0,tail=10000,mid;
		while (head+1<tail)
		{
			mid=(head+tail)/2;
			if (m*mid<=left)
				head=mid;
			else
				tail=mid;
		}
		c.a[i]=head;
		left-=m*head;
	}
	c.check();
	return c;
}

bigint bigint::operator/(int m)

{
	if (m<0)
		return -((*this)/(-m));
	if (m>10000)
		return (*this)/bigint(m);
	bigint c;

	c.oper=oper;
	c.length=length;
	int t=0;
	for (int i=c.length;i>=1;i--)
		c.a[i]=(t=(t%m*10000+a[i]))/m;
	c.check();
	return c;
}

bigint bigint::operator %(bigint m)
{
	return (*this)-((*this)/m)*m;
}

bigint bigint::operator%(int m)
{
	if (m>10000)
		return (*this)%bigint(m);
	int t=0;
	for (int i=length;i>=1;i--)
		t=(t*10000+a[i])%m;
	return t;
}

void bigint::operator+=(bigint m)
{
	(*this)=(*this)+m;
}

void bigint::operator-=(bigint m)
{
	(*this)=(*this)-m;
}

void bigint::operator*=(bigint m)
{
	(*this)=(*this)*m;
}

void bigint::operator/=(bigint m)
{
	(*this)=(*this)/m;
}

void bigint::operator%=(bigint m)
{
	(*this)=(*this)%m;
}

void bigint::operator*=(int m)
{
	(*this)=(*this)*m;
}

void bigint::operator/=(int m)
{
	(*this)=(*this)/m;
}

void bigint::operator%=(int m)

{
	(*this)=(*this)%m;
}

int main()
{
int n;
int t , i;
bigint x2 , y2 , x0 , y0 , x1 , y1 , z1 , z2;
int a1 , a2 , p1 , p2 , q1 , q2 , a , bo;
int ok;

	while (scanf("%d" , &n) == 1)
	{
		if (n == 0) break;
		if (int(sqrt(n)) * int(sqrt(n)) == n) printf("No solution!\n");
		else
		{
			p2 = 0; q2 = 0; ok = 0;
			a = int(floor(sqrt(n)));
			p1 = 0;
			q1 = 1; bo = 0;
			x1 = a; y1 = 1; x0 = 1; y0 = 0;
			a1 = a;
			while ((q2 != 1) || (ok == 0))
			{
				bo ++;
				p2 = a1 * q1 - p1;
				q2 = (n - p2 * p2) / q1;
				a2 = (a + p2) / q2;
				x2 = x1 * a2 + x0;
				y2 = y1 * a2 + y0;
				x0 = x1; y0 = y1;
				x1 = x2; y1 = y2;
				a1 = a2;
				p1 = p2; q1 = q2;
				if (q2 == 1)
				{
					if (bo == 1)
					{
						z1 = y1 * y1 * n + 1;
						z2 = x1 * x1;
						if (z1 == z2) ok = 1;
					}
					else if (bo > 1)
					{
						z1 = y0 * y0 * n + 1;
						z2 = x0 * x0;
						if (z1 == z2) ok = 1;
					}
				}
			}
			if ((bo == 1) && (x1.length <= 250))
			{
				write(x1); printf(" "); writeln(y1);
			}
			else if ((bo > 1) && (x0.length <= 250))
			{
				write(x0); printf(" "); writeln(y0);
			}
			else printf("No solution!\n");
		}
	}
	return 0;
}

