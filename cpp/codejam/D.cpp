#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<numeric>
#include<math.h>
#define ld long double
#define ll long long int
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
#define fi(a,b,c) for(int a=b;a<c;a++)
#define fd(a,b,c) for(int a=b;a>c;a--)
using namespace std;
ll n,k,c,s;

int solve(ll k,ll c,ll s){
   if((double)s<((double)k/(double)c)){
      cout<<"IMPOSSIBLE";
   }else{
      ll temp=0;
      //cout<<((k%c)?(k/c+1)*c:k)<<endl;
         for(int j=0;j<((k%c)?(k/c+1)*c:k);++j){
         temp += ((((-j-1)%c+c)%c)==0?j+1:j)*pow(k,((-j-1)%c+c)%c);
         //cout<<j<<' '<<k<<' '<<((-j+2)%c+c)%c<<endl;
         if(j>=k) temp=j;
         if(((-j-1)%c+c)%c==0){
            cout<<temp<<' ';
            temp=0;
         }
      }
   }
   return 0;
}

int main(){
   cin>>n;
   for(int i=1;i<=n;i++){
      cin>>k>>c>>s;
      cout<<"Case #"<<i<<": ";
      solve(k,c,s);
      cout<<endl;
   }
}
