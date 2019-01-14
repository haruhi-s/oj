#include<bits/stdc++.h>
#define ll long long
#define M 998244353
#define mul(a,b) (a*b%M)
#define div(a,b) ()
using namespace std;

ll powMod(ll n,ll p){
  if(p==1)
    return n;
  ll po=powMod(n,p/2);
  return (p%2?n:1)*po%M*po%M;
}

int main(){
  ll n;
  vector<ll> fac(1000009);
  vector<ll> inf(1000009);
  fac[0]=1;
  cin>>n;
  if(n==1){
    cout<<1;
    return 0;
  }
  for(int k=1;k<=n;++k){
    fac[k]=fac[k-1]*k%M;
  }
  inf[n]=powMod(fac[n],M-2);
  for(int i=n-1;i>=0;i--){
    inf[i]=inf[i+1]*(i+1)%M;
  }
  ll sum=fac[n];
  for(int i=2;i<n;++i){
    sum+= 1ll*(fac[i]-1)*fac[n]%M *inf[i]%M;
  }
  // cout<<fac[3]<<" "<<inf[3]<<" "<<inf[3]*fac[3]%M<<endl;
  sum%=M;
  cout<<sum<<endl;
}
