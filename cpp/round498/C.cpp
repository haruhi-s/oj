#include <bits/stdc++.h>
#define ll long long
#define FOR(i,a,b) for(int i=a;i<=b;++i)
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin>>n;if(n==0){cout<<0<<endl;return 0;}

  int d[200009];
  FOR(i,1,n)
    cin>>d[i];

  ll a=0,b=0,t=0;
  int i=0,j=n+1;

  while(i<j){
    if(a<b){
      ++i;
      a+=d[i];
    }else{
      --j;
      b+=d[j];
    }
    if((a==b)&&(i<j)){
      t=a;
    }
  }
  cout<<t<<endl;
}
