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
int cha[2009],he[2009];
int fac(int n){
   int ret=0;
   fi(i,1,n){
      ret+=i;
   }
   return ret;
}
int n;
int x,y;
ll res;
int main(){
   cin>>n;
   fi(i,0,n){
      cin>>x>>y;
      cha[1002+x-y]++;
      he[x+y]++;
   }
   fi(i,0,2009){
      res+=fac(cha[i]);
      res+=fac(he[i]);
   }
   cout<<res<<endl;
}

