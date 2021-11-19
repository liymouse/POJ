#include <stdio.h>

int main()
{
    char s[2003] = { 0 };
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        char str[3];
        scanf("%s", str);
        s[i] = str[0];
    }
    int x = 0, y = n - 1;
    int L = 0;
    while (x <= y)
    {
        int left = 0;
        for (int i = 0; x + i <= y - i; i ++)
            if (s[x + i] < s[y - i])
            {
                left = 1;
                break;
            }
            else if (s[x + i] > s[y - i])
            {
                left = 0;
                break;
            }
        printf("%c", left ? s[x++] : s[y--]);
        L++;
        if (L % 80 == 0) printf("\n");
    }
    if (n % 80 != 0) printf("\n");
    return 0;
}