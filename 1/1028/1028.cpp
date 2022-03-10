#include <stdio.h>
#include <string.h>

int main()
{
struct kk
{
    int top;
    char s[300][80];
}back , forward;
char ss[80] , c , now[80];
int i , k , L;

    back.top = -1; forward.top = -1;
    strcpy(now , "http://www.acm.org/");
    while (1)
    {
	    scanf("%s" , ss);
	    c = ss[0];
	    if (c == 'Q') break;
	    k = -1;
	    if (c == 'V') scanf("%s" , ss);
	    switch (c)
	    {
            case 'V' :
	            back.top ++; strcpy(back.s[back.top] , now);
	            strcpy(now , ss);
	            forward.top = -1;
	            printf("%s\n" , now);
	        break;
	        case 'B' :
	            if (back.top > -1)
		        {
                    forward.top ++;
                    strcpy(forward.s[forward.top] , now);
                    strcpy(now , back.s[back.top]);
                    back.top --;
                    printf("%s\n" , now);
                }
                else printf("Ignored\n");
            break;
            case 'F' :
                if (forward.top > -1)
                {
                    back.top ++;
                    strcpy(back.s[back.top] , now);
                    strcpy(now , forward.s[forward.top]);
                    forward.top --;    
                    printf("%s\n" , now);
                }
                else printf("Ignored\n");    
            break;
        }
    }    
    return 0;
}    
