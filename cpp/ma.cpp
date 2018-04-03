#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
char s[200009];int a[30],i,sum;
queue<char> q;
int main(){
   cout<<"gg";
   cin>>s;
   cout<<sizeof(s);
   for(;i<sizeof(s);++a[s[i]-'a']);
   cout<<s;
   if(sizeof(s)%2==0){
      for(int j=0;j<26;j++)
         if(a[j]%2)q.push((char)a[j]);
      while(!q.empty()){++a[q.front()-'a'];q.pop();--a[q.front()-'a'];q.pop();}
      for(int j=0;j<26;j++){
         for(int t;t<a[j];t+=2)cout<<'a'+j;
      }
      for(int j=26;j>=0;j--){
         for(int t;t<a[j];t+=2)cout<<'a'+j;
      }
   }
   if(sizeof(s)%2==1){

   }
}
