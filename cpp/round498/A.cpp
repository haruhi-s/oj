#include <bits/stdc++.h>
#define ll long long
#define FOR(i,a,b) for(int i=a;i<=b;++i)
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin>>n;
  int a[1009];
  FOR(i,1,n){
    cin>>a[i];
    if(a[i]%2==0)
      --a[i];
  }
  FOR(i,1,n)
    cout<<a[i]<<endl;
  return 0;
}
