#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#define ll long long int
using namespace std;
int n,m,g[19],b,r;
int main(){
   cin>>n>>m;
   for(int i=0;i<n;i++){
      cin>>b;
      g[b]++;
   }
   for(int i=1;i<=m;i++){
      for(int j=1;j<i;j++){
         r+=g[i]*g[j];
      }
   }
   cout<<r;
}

