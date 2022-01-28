#include <stdio.h>

int main()
{
int map[201][201] = {0};
int i , j , k , s , t , w , n , m;

    scanf("%d %d" , &n , &m);
    for (i = 0; i < m; i ++)
    {
        scanf("%d %d %d" , &s , &t , &w);
        map[s][t] = w; map[t][s] = w;
    }
    for (k = 1; k <= n; k ++)
        for (i = 1; i <= n; i ++)
            if (k != i)
                for (j = 1; j <= n; j ++)
                    if ((j != i) && (j != k) && (map[i][k] > 0) && (map[k][j] > 0) &&
                        ((map[i][j] == 0) || (map[i][k] + map[k][j] < map[i][j])))
                    {
                        map[i][j] = map[i][k] + map[k][j];
                    }
    //此时map[i][j]表示i到j的最短路 
    printf("1-->%d : %d" , n , map[1][n]);
    getchar(); getchar();
    return 0;
}
