#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
using namespace std;

string getFirst(int w)
{
    string res = "";
    for (int i = 0; i < w; i++) res += "()";
    return res;
}
int last(string s)
{
    for (int i = 0; i < s.size() / 2; i++)
        if (s[i] == ')') return 0;
    return 1;
}
string getNext(string s)
{
    if (s.size() == 0) return "()";
    int level = 0;
    int k = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '(') level++;
        else
        {
            level--;
            if (level == 0) { k = i; break; }
        }
    string a = "", b = "";
    for (int i = 1; i < k; i++) a += s[i];
    for (int i = k + 1; i < s.size(); i++) b += s[i];
    if (!last(b)) return "(" + a + ")" + getNext(b);
    else if (!last(a)) return "(" + getNext(a) + ")" + getFirst(b.size() / 2);
    else if (b.size() > 0) return "(" + getFirst(a.size() / 2 + 1) + ")" + getFirst(b.size() / 2 - 1);
    else return getFirst(s.size() / 2 + 1);
}
int main()
{
    int n;
    char ss[200];
    scanf("%d", &n); gets_s(ss);
    for (int ca = 0; ca < n; ca++)
    {
        gets_s(ss);
        string s = "";
        int L = strlen(ss);
        for (int i = 0; i < L; i++)
            if (ss[i] == '(' || ss[i] == ')') s += ss[i];
        string res = getNext(s);
        for (int i = 0; i < res.length(); i++) printf("%c ", res[i]);
        printf("$\n");
    }
    return 0;
}
