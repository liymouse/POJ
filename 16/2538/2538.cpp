#include <stdio.h>
#include <string.h>

char change(char x)
{
	switch(x)
	{
		case '1' : return '`'; break;
		case '0' : return '9'; break;
		case '-' : return '0'; break;
		case '=' : return '-'; break;
		case 'W' : return 'Q'; break;
		case 'E' : return 'W'; break;
		case 'R' : return 'E'; break;
		case 'T' : return 'R'; break;
		case 'Y' : return 'T'; break;
		case 'U' : return 'Y'; break;
		case 'I' : return 'U'; break;
		case 'O' : return 'I'; break;
		case 'P' : return 'O'; break;
		case '[' : return 'P'; break;
		case ']' : return '['; break;
		case '\\' : return ']'; break;
		case 'S' : return 'A'; break;
		case 'D' : return 'S'; break;
		case 'F' : return 'D'; break;
		case 'G' : return 'F'; break;
		case 'H' : return 'G'; break;
		case 'J' : return 'H'; break;
		case 'K' : return 'J'; break;
		case 'L' : return 'K'; break;
		case ';' : return 'L'; break;
		case '\'' : return ';'; break;
		case 'X' : return 'Z'; break;
		case 'C' : return 'X'; break;
		case 'V' : return 'C'; break;
		case 'B' : return 'V'; break;
		case 'N' : return 'B'; break;
		case 'M' : return 'N'; break;
		case ',' : return 'M'; break;
		case '.' : return ','; break;
		case '/' : return '.'; break;
		case ' ' : return ' '; break;
		case '\n' : return '\n'; break;
		default : return x - 1; break;
	}
}

int main()
{
char c;
int i , L;

	while (scanf("%c" , &c) == 1)
		printf("%c" , change(c));
	return 0;
}