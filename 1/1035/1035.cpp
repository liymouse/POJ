#include <iostream.h>
#include <string.h>

struct kk
{
    char word[20];
    int L;
}a[10000];
char ss[20];
int n;
    
void check(char s[] , int Long)
{
int i , j , x , p , q , bo;

    bo = 0;
    cout << ss;
    for (i = 0; i < n; i ++)
        if (Long == a[i].L)
        {
            x = 0;
            for (j = 0; j < Long; j ++)
                if (s[j] != a[i].word[j]) {x ++; break;}
            if (x == 0) {cout << " is correct"; bo = 1;}
            if (bo) break;
        }
    if (bo == 0) cout << ":";
    else return;
    for (i = 0; i < n; i ++)
        if (Long == a[i].L)
        {
            x = 0;
            for (j = 0; j < Long; j ++)
                if (s[j] != a[i].word[j]) x ++;
            if (x == 1)
            cout << " " << a[i].word;
        }
        else if (Long == a[i].L + 1)
             {
                 p = 0; q = 0; x = 0;
                 while (s[p] != 0)
                 {
                     if (x > 1) break;
                     if (s[p] == a[i].word[q]) {p ++ ; q ++;}
                     else {p ++; x ++;}
                 }
                 if (x == 1)
                 cout << " " << a[i].word;
             }
             else if (Long + 1 == a[i].L)
                  {
                      p = 0; q = 0; x = 0;
                      while (a[i].word[q] != 0)
                      {
                          if (x > 1) break;
                          if (s[p] == a[i].word[q]) {p ++; q ++;}
                          else {x ++; q ++;}
                      }
                      if (x == 1)
                      cout << " " << a[i].word;
                  }
}
    
int main()
{
    n = 0;
    while (cin >> ss)
    {
        if (ss[0] == '#') break;
        else 
        {
            strcpy(a[n].word , ss);
            a[n++].L = strlen(ss);
        }    
    }
    while (cin >> ss)
    {
        if (ss[0] == '#') break;
        else 
        {
            
            check(ss , strlen(ss));
            cout << endl;
        }    
    }    
    return 0;
}

