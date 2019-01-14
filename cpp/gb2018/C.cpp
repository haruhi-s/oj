#include<bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
  ll n; int f=0; ll fac[10009];
  cin >> n;
  for(int i=1; i<=(int)sqrt(n);i++){
    if(0==(n%i)){
      fac[f]=i;
      f++;
    }
  }
  for(int i=0; i<f; i++){
    cout<< fac[i] + (fac[i]-1) * n/2 << " ";
  }
  int ff;
  for(int i=f-1;i>=0;i--){
    if(n==fac[i]*fac[i])continue;
    ff = n/fac[i];
    cout<< ff + (ff-1)*n/2<<" ";
  }
  cout<<endl;
}
