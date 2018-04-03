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

pair<ll,ll> solve(ll n,ll k){
  ll l = (n%2) ? (n-1)/2 : n/2 - 1;
  ll r = (n%2) ? (n-1)/2 : n/2;
  if (k == 1) return pair<ll,ll>(l,r);
  if (k % 2) return solve(l,(k-1)/2);
  else return solve(r,k/2);
}

int main(){
  ll t,n,k;
  cin>>t;
  for(int i=1;i<=t;i++){
    cin>>n>>k;
    pair<ll,ll> x = solve(n,k);
    ll a = x.first;
    ll b = x.second;
    cout << "Case #" << i << ": " << b << ' ' << a << endl;
  }
  return 0;
}
