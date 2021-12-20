#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    char s[300];
    while (scanf("%s", s) == 1)
    {
        if (s[0] == '8') break;
        int a = 0, b = 0;
        int m[256] = { 0 };
        int p = 0;
        for (int i = 0; i < 256; i++)
            if ('0' <= s[i] && s[i] <= '9') m[i] = s[i] - '0';
            else m[i] = s[i] - 'A' + 10;
        int t, sum;
        while (m[p] != 8)
        {
            switch (m[p])
            {
            case 0:
                a = m[m[p + 1] * 16 + m[p + 2]]; p+=3;
                break;
            case 1:
                m[m[p + 1] * 16 + m[p + 2]] = a; p+=3;
                break;
            case 2:
                t = a; a = b; b = t; p++;
                break;
            case 3:
                sum = a + b;
                a = sum % 16; b = sum / 16; p++;
                break;
            case 4:
                a = (a + 1) % 16; p++;
                break;
            case 5:
                a = (a - 1 + 16) % 16; p++;
                break;
            case 6:
                if (a == 0) p = m[p + 1] * 16 + m[p + 2]; else p += 3;
                break;
            case 7:
                p = m[p + 1] * 16 + m[p + 2];
                break;
            case 8:
            default:
                break;
            }
        }
        for (int i = 0; i < 256; i++)
            if (m[i] < 10) s[i] = '0' + m[i];
            else s[i] = 'A' + m[i] - 10;
        printf("%s\n", s);
    }
    return 0;
}