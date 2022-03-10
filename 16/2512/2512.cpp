#include <stdio.h>
#include <string.h>

int p[8][2] = {{-1 , -1} , {-1 , 0} , {-1 , 1} , {0 , -1} , {0 , 1} , {1 , -1} , {1 , 0} , {1 , 1}};
int q[8][2] = {{-1 , -2} , {-2 , -1} , {-2 , 1} , {-1 , 2} , {1 , 2} , {2 , 1} , {2 , -1} , {1 , -2}};

int main()
{
int a[8][8] = {0};
char s[1000];
int tot , L , i , j , t , k , x , y;

    while (scanf("%s" , s) == 1)
    {
        for (i = 0; i < 8; i ++) for (j = 0; j < 8; j ++) a[i][j] = 0;
        L = strlen(s);
        i = 0; j = 0;
        for (t = 0; t < L; t ++)
        {
            if ((s[t] <= '9') && (s[t] >= '0'))
                j += s[t] - '0';
            else if (((s[t] >= 'a') && (s[t] <= 'z')) || ((s[t] >= 'A') && (s[t] <= 'Z')))
                a[i][j++] = s[t];
			else if (s[t] == '/') {i ++; j = 0;}
        }
        for (i = 0; i < 8; i ++)
            for (j = 0; j < 8; j ++)
            {
                switch (a[i][j])
                {
                    case (int)'Q' : case (int)'q' :
                        y = j;
                        x = i + 1;
                        while (x < 8)
                        {
                            if (a[x][y] == 0) a[x][y] = 1;
                            else if (a[x][y] > 1) break;
                            x ++;
                        }
                        x = i - 1;
                        while (x >= 0)
                        {
                            if (a[x][y] == 0) a[x][y] = 1;
                            else if (a[x][y] > 1) break;
                            x --;
                        }
                        x = i;
                        y = j + 1;
                        while (y < 8)
                        {
                            if (a[x][y] == 0) a[x][y] = 1;
                            else if (a[x][y] > 1) break;
                            y ++;
                        }
                        y = j - 1;
                        while (y >= 0)
                        {
                            if (a[x][y] == 0) a[x][y] = 1;
                            else if (a[x][y] > 1) break;
                            y --;
                        }
                        x = i+1; y = j+1;
                        while ((x < 8) && (y < 8)) 
                        {
                            if (a[x][y] == 0) a[x][y] = 1;
                            else if (a[x][y] > 1) break;
                            x ++; y ++;
                        }
                        x = i - 1; y = j - 1;
                        while ((x >= 0) && (y >= 0))
                        {
                            if (a[x][y] == 0) a[x][y] = 1; 
                            else if (a[x][y] > 1) break;
                            x --; y --;
                        }
                        x = i - 1; y = j + 1;
                        while ((x >= 0) && (y < 8))
                        {
                            if (a[x][y] == 0) a[x][y] = 1; 
                            else if (a[x][y] > 1) break;
                            x --; y ++;
                        }
                        x = i + 1; y = j - 1;
                        while ((x < 8) && (y >= 0))
                        {
                            if (a[x][y] == 0) a[x][y] = 1; 
                            else if (a[x][y] > 1) break;
                            x ++; y --;
                        }
                    break;
                    case (int)'K' : case (int)'k':
                        for (k = 0; k < 8; k ++)
                        {
                            x = i + p[k][0]; y = j + p[k][1];
                            if ((x >= 0) && (x < 8) && (y >= 0) && (y < 8))
                                if (a[x][y] == 0) a[x][y] = 1;
                        }
                    break;
                    case (int)'N' : case (int)'n':
                        for (k = 0; k < 8; k ++)
                        {
                            x = i + q[k][0]; y = j + q[k][1];
                            if ((x >= 0) && (x < 8) && (y >= 0) && (y < 8))
                                if (a[x][y] == 0) a[x][y] = 1;
                        }
                    break;
                    case (int)'R' : case (int)'r':
                        y = j;
                        x = i + 1;
                        while (x < 8)
                        {
                            if (a[x][y] == 0) a[x][y] = 1;
                            else if (a[x][y] > 1) break;
                            x ++;
                        }
                        x = i - 1;
                        while (x >= 0)
                        {
                            if (a[x][y] == 0) a[x][y] = 1;
                            else if (a[x][y] > 1) break;
                            x --;
						}
						x = i;
                        y = j + 1;
                        while (y < 8)
                        {
                            if (a[x][y] == 0) a[x][y] = 1;
                            else if (a[x][y] > 1) break;
                            y ++;
                        }
                        y = j - 1;
                        while (y >= 0)
                        {
                            if (a[x][y] == 0) a[x][y] = 1;
                            else if (a[x][y] > 1) break;
                            y --;
                        }
                    break;
                    case (int)'B' : case (int)'b':
                        x = i+1; y = j+1;
                        while ((x < 8) && (y < 8)) 
                        {
                            if (a[x][y] == 0) a[x][y] = 1;
                            else if (a[x][y] > 1) break;
                            x ++; y ++;
                        }
                        x = i - 1; y = j - 1;
                        while ((x >= 0) && (y >= 0))
                        {
                            if (a[x][y] == 0) a[x][y] = 1; 
                            else if (a[x][y] > 1) break;
                            x --; y --;
                        }
                        x = i - 1; y = j + 1;
                        while ((x >= 0) && (y < 8))
                        {
                            if (a[x][y] == 0) a[x][y] = 1; 
                            else if (a[x][y] > 1) break;
                            x --; y ++;
                        }
                        x = i + 1; y = j - 1;
                        while ((x < 8) && (y >= 0))
                        {
                            if (a[x][y] == 0) a[x][y] = 1; 
                            else if (a[x][y] > 1) break;
                            x ++; y --;
                        }
                    break;
                    case (int)'p' :
                        if ((i + 1 < 8) && (j - 1 >= 0))
                            if (a[i+1][j-1] == 0) a[i+1][j-1] = 1;
                        if ((i + 1 < 8) && (j + 1 < 8))
                            if (a[i+1][j+1] == 0) a[i+1][j+1] = 1;
                    break;
                    case (int)'P' :
                        if ((i - 1 >= 0) && (j - 1 >= 0))
                            if (a[i-1][j-1] == 0) a[i-1][j-1] = 1;
                        if ((i - 1 >= 0) && (j + 1 < 8))
                            if (a[i-1][j+1] == 0) a[i-1][j+1] = 1;
                    break;
                }
            }
        tot = 0;
        for (i = 0; i < 8; i ++)
            for (j = 0; j < 8; j ++)
                if (a[i][j] == 0) tot ++;
        printf("%d\n" , tot);
    }
    return 0;
}
