#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
  int n,k,h[100009];
  cin>>n>>k;
  for(int i=0;i<n;i++)
    cin>>h[i];
  int p = h[0];
  int s = 1, max=1;
  for(int i=1;i<n;i++){
    if(p!=h[i]){
      s++;
      max=s>max?s:max;
    }else{
      s=1;
    }
    p=h[i];
  }
  cout<<max<<endl;
}
