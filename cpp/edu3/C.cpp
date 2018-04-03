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
int n,m[100009];
int main(){
   cin>>n;
   for(int i=0;i<n;cin>>m[i],i++);
   sort(m,m+n);
   int s=accumulate(m,m+n,0);
   int rem=s%n;
   rem=(n-rem);
   int quo=s/n;
   int res=0;
   for(int i=0;i<n;i++){
      if(i>=rem){
         res+=abs(m[i]-quo-1);
      }else{
         res+=abs(m[i]-quo);
      }
      //cout<<res<<endl;
   }
   res>>=1;
   cout<<res;
}

