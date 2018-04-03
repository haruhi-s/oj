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
int n;
ll res;
int f[200009];
int main(){
   cin>>n;
   int t=0;
   for(int i=0;i<n;i++){
      cin>>t;
      f[t]=i;
   }
   for(int i=1;i<n;i++){
      res+=abs(f[i]-f[i+1]);
   }
   cout<<res;
}
