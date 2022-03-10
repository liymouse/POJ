# include <iostream>
# include <vector>
# include <algorithm>
# include <string>
using namespace std;
struct dir
{
     string name;
     vector<dir> mulu;
     vector<string> file;

};
void deal(dir &t,string str)
{
     if(str.at(0)=='*'||str.at(0)==']') return;
     else if(str.at(0)=='f')
     {
        t.file.push_back(str);
        cin>>str;
        deal(t,str);
     }
     else
     {
         dir t1;
         t1.name=str;
         cin>>str;
         deal(t1,str);
         t.mulu.push_back(t1);
         cin>>str;
         deal(t,str);
     }
}
void print_layer(int n)
{
     for(int i=1;i<=n;i++) cout<<"|     ";
}
void print(dir &p,int layer)
{
     print_layer(layer);
     cout<<p.name<<endl;
     for(int i=0;i<p.mulu.size();i++)
     {
        print(p.mulu[i],layer+1);
     }
    sort(p.file.begin(),p.file.end());
     for(int i=0;i<p.file.size();i++)
     {
       print_layer(layer);
       cout<<p.file[i]<<endl;
     }
}

 int main()
{
    string temp;
    int count=1;
    while(1)
    {
      cin>>temp;
      dir root;
      root.name="ROOT";
      if(temp.at(0)=='#') break;
      deal(root,temp);
      cout<<"DATA SET "<<count++<<":"<<endl;
      print(root,0);
      cout<<endl;
    }
     return 0;
}
          
