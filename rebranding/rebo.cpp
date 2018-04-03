#include <iostream>
using namespace std;
int n,m;
string x;
char a,b,c[26];
int main()
{
   for(int i=0;i<26;i++)
      c[i]=i+'a';
   cin>>n>>m>>x;
   while(m--)
   {
      cin>>a>>b;
      for(int i=0;i<26;i++)
      {
         if(c[i]==a)
            c[i]=b;
         else if(c[i]==b)
            c[i]=a;
      }}
      for(int i=0;i<n;i++)
         cout<<c[x[i]-'a'];
}
