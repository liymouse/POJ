#include <stdio.h>

int main()
{
int a[6] , b[6] , c[3];
int i , j , k , bo , dif , x , y , z;

    dif = 0; c[0] = -1; c[1] = -1; c[2] = -1;
    for (i = 0; i < 6; i ++) 
    {
        scanf("%d %d" , &a[i] , &b[i]);
        bo = 0;
        for (j = 0; j < dif; j ++)
            if (a[i] == c[j]) {bo = 1; break;}
        if (bo == 0) c[dif++] = a[i];
        bo = 0;
        for (j = 0; j < dif; j ++)
            if (b[i] == c[j]) {bo = 1; break;}
        if (bo == 0) c[dif++] = b[i];
        if (a[i] > b[i]) {k = a[i]; a[i] = b[i]; b[i] = k;}
    }
    if (dif > 3) printf("IMPOSSIBLE\n");
    else if (dif == 1) printf("POSSIBLE\n");
    else if (dif == 2)
    {
        if (c[0] > c[1]) {k = c[0]; c[0] = c[1]; c[1] = k;}
        k = 0;
        for (i = 0; i < 6; i ++) 
            if ((a[i] == c[0]) && (b[i] == c[1])) k ++;
        if (k == 4) printf("POSSIBLE\n");
        else printf("IMPOSSIBLE\n");
    }
    else
    {
        for (i = 0; i < 3; i ++)
            for (j = 1; j < 3 - i; j ++)
                if (c[j-1] > c[j]) {k = c[j-1]; c[j-1] = c[j]; c[j] = k;}
        x = 0; y = 0; z = 0;
        for (i = 0; i < 6; i ++)
            if ((a[i] == c[0]) && (b[i] == c[1])) x ++;
            else if ((a[i] == c[0]) && (b[i] == c[2])) y ++;
                else if ((a[i] == c[1]) && (b[i] == c[2])) z ++;
        if ((z == 2) && (y == 2) && (x == 2)) printf("POSSIBLE\n");
        else printf("IMPOSSIBLE\n");
    }
    return 0;
}
