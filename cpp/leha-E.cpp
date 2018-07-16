#include<bits/stdc++.h>
#define M 998244353
#define ll long long
using namespace std;
ll  po[1000009];
int n;
int a[1000009];

int main(){
  // ios::sync_with_stdio(false);
  // cin.tie(nullptr);
  // cout.tie(nullptr);

  cin>>n;
  for(int i=1;i<=n;++i)
    cin>>a[i];
  po[0]=1;
  for(int i=1;i<=n;++i){
    po[i]=(po[i-1]*2)%M;
    // cout<<po[i]<<" ";
  }
  ll ans=0;
  for(int i=1;i<n;++i){
    ans=(ans+po[n-1-i]*a[i] % M * (n-i+2)) % M;
  }
  ans = (ans + a[n]) % M;
  cout<<ans<<endl;
  return 0;
}
