#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<numeric>
#define ll long long int
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
#define fi(a,b,c) for(int a=b;a<c;a++)
#define fd(a,b,c) for(int a=b;a>c;a--)
using namespace std;
int cha[2009];
int he[2009];
int n,t1,t2;
ll fac(int n){
   ll ret=1;
   fi(i,2,n+1){
      ret*=i;
   }
   return ret;
}
ll com(int n,int k){
   return fac(n)/fac(k)/fac(n-k);
}
int main(){
   fi(i,0,2009){
      cha[i]=0;
      he[i]=0;
   }
   cin>>n;
   fi(i,0,n){
      cin>>t1>>t2;
      cha[t1-t2+1000]++;
      he[t1+t2]++;
   }
   ll res;
   fi(i,0,2009){
      res+=fac(cha[i])/2;
      res+=fac(he[i])/2;
   }
   cout<<res;
}
