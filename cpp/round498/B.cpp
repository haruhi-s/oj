#include <bits/stdc++.h>
#define ll long long
#define FOR(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int a[2009];
int b[2009];

bool cp (int i,int j) {
  return (a[i]>a[j]);
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n,k;
  cin>>n>>k;
  FOR(i,1,n){
    cin>>a[i];
    b[i]=i;
  }
  sort(b+1,b+n+1,cp);
  sort(b+1,b+k+1);
  int sum=0,last=0;
  FOR(i,1,k){
    sum+=a[b[i]];
  }
  cout<<sum<<endl;
  FOR(i,1,k-1){
    cout<<b[i]-last<<" ";
    last=b[i];
  }
  cout<<n-last<<endl;
}
