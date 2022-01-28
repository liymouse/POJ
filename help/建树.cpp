#include <stdio.h>

int b[100] = {0};
int pre[100] = {0} , last[100] = {0}, child[100] = {0};

void dfs(int x)
{
int y;

    b[x] = 1;
    while (last[x] > 0)
    {
        y = child[last[x]];
        if (b[y] == 0)
        {
            dfs(y);
            printf("%d " , y);
        }
        last[x] = pre[last[x]];
    }
}

int main()
{
int i , c , n , x , y;

    scanf("%d" , &n);
    c = 0;
    last[0] = 1;
    for (i = 0; i < n-1; i ++)
    {
        scanf("%d %d" , &x , &y);
        c ++; pre[c] = last[x]; last[x] = c; child[c] = y;
        c ++; pre[c] = last[y]; last[y] = c; child[c] = x;
    }
    printf("\n");
    printf("pre     ");
    for (i = 1; i <= n; i ++)
        printf("%d " , pre[i]);
    printf("\n");
    printf("last    ");
    for (i = 1; i <= n; i ++)
        printf("%d " , last[i]);
    printf("\n");
    printf("child   ");
    for (i = 1; i <= n; i ++)
        printf("%d " , child[i]);
    printf("\n\n");
    

    dfs(0);
    
    /*printf("\n");
    printf("pre     ");
    for (i = 1; i <= n; i ++)
        printf("%d " , pre[i]);
    printf("\n");
    printf("last    ");
    for (i = 1; i <= n; i ++)
        printf("%d " , last[i]);
    printf("\n");
    printf("child   ");
    for (i = 1; i <= n; i ++)
        printf("%d " , child[i]);
    printf("\n\n");
    */
    getchar(); getchar();
    return 0;
}
