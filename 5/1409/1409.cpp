#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef struct
{
    char word[55], digit[55];
    int L;
}Word;
Word a[100];
char d[] = "22233344455566677778889999";
char num[305];
int res[305], n;
int cmp(Word &x, Word &y)
{
    return strcmp(x.word, y.word) < 0;
}
void find(int x, int k)
{
    if (num[x] == 0)
    {
        for (int i = 0; i < k - 1; i++) printf("%s ", a[res[i]].word);
        printf("%s.\n", a[res[k - 1]].word);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        int match = 1;
        for (int j = 0; j < a[i].L; j ++)
            if (a[i].digit[j] != num[x + j]) { match = 0; break; }
        if (match)
        {
            res[k] = i;
            find(x + a[i].L, k + 1);
        }
    }
}
int main()
{
    while (scanf("%d", &n) == 1)
    {
        if (n == 0) break;
        for (int i = 0; i < n; i++)
        {
            scanf("%s", a[i].word);
            a[i].L = strlen(a[i].word);
            for (int j = 0; a[i].word[j] != 0; j++)
                a[i].digit[j] = d[a[i].word[j] - 'a'];
        }
        scanf("%s", num);
        sort(a, a + n, cmp);
        find(0, 0);
        printf("--\n");
    }
    return 0;
}
