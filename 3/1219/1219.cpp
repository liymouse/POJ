#include <stdio.h>
#include <string.h>
int main()
{
    char word[10];
    char ans[100];
    //freopen("1219.in", "r", stdin);
    //freopen("1219.out", "w", stdout);
    while (scanf("%s", word) == 1)
    {
        if (strcmp(word, "LINGO") == 0) break;
        int num[26] = { 0 };
        for (int i = 0; i < 5; i++) num[word[i] - 'A'] ++;
        gets_s(ans);
        char out[10] = ".....";
        out[0] = word[0];
        printf("\n%s\n", out);
        int finish = 0;
        int time = 6;
        while (gets_s(ans))
        {
            if (ans[0] == 0)
            {
                if (time == 6)
                {
                    for (int i = 0; i < 5; i++)
                        printf("%c", word[i] - 'A' + 'a');
                    printf("\n");
                }
                break;
            }
            if (finish || time == 0) continue;
            int valid = 1;
            time--;
            if (ans[5] != 0) valid = 0;
            for (int i = 0; i < 5; i++)
                if (ans[i] < 'A' || ans[i] > 'Z') valid = 0;
            if (!valid) printf("%s\n", out);
            else
            {
                memset(out, 0, sizeof(out));
                int remain[26];
                for (int i = 0; i < 26; i++) remain[i] = num[i];
                finish = 1;
                for (int i = 0; i < 5; i++)
                    if (ans[i] == word[i])
                    {
                        out[i] = ans[i]; remain[ans[i] - 'A'] --;
                    }
                    else finish = 0;
                if (time == 0 && !finish)
                {
                    for (int i = 0; i < 5; i++)
                        printf("%c", word[i] - 'A' + 'a');
                    printf("\n");
                }
                else
                {
                    for (int i = 0; i < 5; i++)
                        if (out[i] == 0 && remain[ans[i] - 'A'] > 0)
                        {
                            out[i] = ans[i] - 'A' + 'a';
                            remain[ans[i] - 'A'] --;
                        }
                    for (int i = 0; i < 5; i++)
                        if (out[i] == 0) out[i] = '.';
                    out[5] = 0;
                    printf("%s\n", out);
                }
            }
        }
    }
    return 0;
}