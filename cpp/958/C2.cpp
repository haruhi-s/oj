#include<bits/stdc++.h>

using namespace std;

int main(){
  int N,k,p;
  vector<int> A(100009);
  cin>>N>>k>>p;
  int ans=0;k--;int cur=0,a;
  for(int i=0;i<N;i++){
    cin>>A[i];A[i]%=p;
    a=A[i];
    if(cur+a>=p){
      if(k){
        ans+=cur;
        cur=a;
      }else{
        cur+=a;cur%=p;
      }
    }else{
      cur+=a;
    }
  }
  ans+=cur;
  cout<<ans<<endl;
}
