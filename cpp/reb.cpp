#include<iostream>
using namespace std;
int main(){
   int n,m;
   char a,b,d[26];
   for(int i=0;i<26;i++)d[i]=i+'a';
   cin >> n >> m;
   char c[n];
   cin >> c;
   while(m--){
      cin >> a >> b;
      for(int j=0;j<26;j++){
         if(d[j]==a)d[j]=b;
         else if(d[j]==b)d[j]=a;
      }
   }
   for(int i=0;i<n;i++)
      cout<<d[c[i]-'a'];
   return 0;
}
