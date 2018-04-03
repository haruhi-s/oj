#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<numeric>
#define ll long long int
using namespace std;
int n,a[109];
int main(){
   cin>>n;
   int y=0;
   ll r=1,tr=1;
   for(int i=0;i<n;i++)cin>>a[i];
   for(int i=0;i<n;i++){
      if(y){
         if(!a[i])tr++;
         else{
            r*=tr;
            tr=1;
         }
      }
      if(a[i])y=1;
   }
   if(y==0){
      cout<<0<<endl;
      return 0;
   }
   if(r)cout<<r;
   else cout<<1;
}

