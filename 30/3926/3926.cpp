#include <stdio.h>
#include <algorithm>
using namespace std;   

#define N 10010   
int n , m , L;
int x;
int line[N], v[115][N] , len[N] , dp[2][N];
char s[2000001];   

int getint()  
{  
    int data = 0 , u = 1;
    while (s[x] < '0' || s[x] > '9' ) x++;  
    if (x > 0 && s[x-1] == '-') u = -1;  
    while (s[x] >= '0' && s[x] <= '9')   
    {
        data = data * 10 + s[x] - '0';    
        x ++;  
    }  
    return data * u;
}  

int main()  
{   
    while (scanf("%d %d %d" , &n , &m , &L) == 3 , n)
    {
        gets(s);
        n ++;
        for (int i = 1; i <= n; i ++)
        {  
            gets(s); x = 0;  
            v[i][0] = 0;  
            for (int j = 1; j <= m; j ++)   
            {  
                v[i][j] = getint();  
                v[i][j] += v[i][j-1];  
            }
        }
        int t = 0;
        len[0] = 0;  
        memset(dp[t] , 0 , sizeof(dp[t]));  
        for (int k = 1; k <= n; k ++)  
        {
            t = !t;
            gets(s); x = 0;
            for (int i = 1; i <= m; i ++)   
            {  
                len[i] = getint();
                len[i] += len[i-1];      
            }  
            memset(dp[t] , 0 , sizeof(dp[t]));  
            int h1 = 1 , h2 = 0;
            for (int i = 0; i <= m; i ++)  
            {   
                while (h1 <= h2 && len[i] - len[line[h1]] > L) h1 ++;   
                while (h1 <= h2 && dp[!t][line[h2]] + v[k][i] - v[k][line[h2]] <= dp[!t][i]) h2 --;  
                line[++h2] = i;
                dp[t][i] = dp[!t][line[h1]] + v[k][i] - v[k][line[h1]];
            }//  单调队列1 左往右    
            h1 = 1; h2 = 0;   
            for (int i = m; i >= 0; i--)  
            {
                while (h1 <= h2 && len[line[h1]] - len[i] > L) h1 ++;   
                while (h1 <= h2 && dp[!t][line[h2]] + v[k][line[h2]] - v[k][i] <= dp[!t][i]) h2 --;  
                line[++h2] = i;
                dp[t][i] = max(dp[t][i] , dp[!t][line[h1]] + v[k][line[h1]] - v[k][i]);
            }//  单调队列2 右往左                               
        }      
        int res = 0;
        for (int i = 0; i <= m; i ++) res = max(res , dp[t][i]);
        printf("%d\n" , res);    
    }  
    return 0;  
} 
