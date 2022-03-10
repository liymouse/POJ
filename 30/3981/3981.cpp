#include <cstdio>
#include <string>
using namespace std;

int main()
{
    char str[1100];
    while (gets(str))
    {
        string s(str);
        for(int pos = s.find("you"); pos != -1; pos = s.find("you", pos+2)) 
        {
            s.replace(pos , 3 , "we");
        }
        puts(s.c_str());
    }
    return 0;
}
