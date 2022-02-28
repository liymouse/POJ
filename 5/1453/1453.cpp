#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char s[10010];
int main()
{
    int a[26], b[26];
    for (int i = 0; i < 26; i++) a[i] = b[i] = i;
    while (gets_s(s))
    {
        char com[8] = "";
        for (int i = 0; i < 7; i++)
            if ('A' <= s[i] && s[i] <= 'Z') com[i] = s[i] - 'A' + 'a';
            else com[i] = s[i];
        if (!strcmp(com, "encrypt") && s[7] == ' ')
        {
            int pre = 0;
            printf("RESULT:  ");
            int si = 8;
            while (s[si] == ' ') si++;
            for (int i = si; s[i] != 0; i++)
            {
                if ('A' <= s[i] && s[i] <= 'Z')
                {
                    printf("%c", b[(a[s[i] - 'A'] - a[pre] + 26) % 26] + 'A');
                    pre = s[i] - 'A';
                }
                else if ('a' <= s[i] && s[i] <= 'z')
                {
                    printf("%c", b[(a[s[i] - 'a'] - a[pre] + 26) % 26] + 'a');
                    pre = s[i] - 'a';
                }
                else
                {
                    printf("%c", s[i]);
                    pre = 0;
                }
            }
            printf("\n");
        }
        else if (!strcmp(com, "decrypt") && s[7] == ' ')
        {
            int pre = 0;
            printf("RESULT:  ");
            int si = 8;
            while (s[si] == ' ') si++;
            for (int i = si; s[i] != 0; i++)
            {
                if ('A' <= s[i] && s[i] <= 'Z')
                {
                    printf("%c", b[(a[pre] + a[s[i] - 'A']) % 26] + 'A');
                    pre = b[(a[pre] + a[s[i] - 'A']) % 26];
                }
                else if ('a' <= s[i] && s[i] <= 'z')
                {
                    printf("%c", b[(a[pre] + a[s[i] - 'a']) % 26] + 'a');
                    pre = b[(a[pre] + a[s[i] - 'a']) % 26];
                }
                else
                {
                    printf("%c", s[i]);
                    pre = 0;
                }
            }
            printf("\n");
        }
        else if (!strcmp(com, "cipher "))
        {
            int c[26], d[26] = { 0 };
            memset(c, 0xff, sizeof(c));
            int k = 0;
            int bad = 0;
            for (int i = 7; s[i] != 0; i++)
            {
                if (k >= 26) {
                    bad = 1; break;
                }
                if ('A' <= s[i] && s[i] <= 'Z')
                {
                    c[s[i] - 'A'] = k;
                    d[k++] = s[i] - 'A';
                }
                else if ('a' <= s[i] && s[i] <= 'z')
                {
                    c[s[i] - 'a'] = k;
                    d[k++] = s[i] - 'a';
                }
            }
            for (int i = 0; i < 26; i ++)
                if (c[i] < 0) { bad = 1; break; }
            if (bad)
            {
                printf("Bad cipher.  Using default.\n");
                for (int i = 0; i < 26; i++) a[i] = b[i] = i;
            }
            else
            {
                printf("Good cipher.  Using ");
                for (int i = 0; i < 26; i++) printf("%c", d[i] + 'A');
                printf(".\n");
                for (int i = 0; i < 26; i++) {
                    a[i] = c[i]; b[i] = d[i];
                }
            }
        }
        else
        {
            printf("Command not understood.\n");
        }
    }
    return 0;
}
