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
int n,s,r=0,r1,r2;
int main(){
   cin>>n>>s;
   r=s;
   for(int i=0;i<n;i++){
      cin>>r1>>r2;
      r=max(r1+r2,r);
   }
   cout<<r;
}

