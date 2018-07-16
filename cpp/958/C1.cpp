#include<bits/stdc++.h>

using namespace std;

int main(){
  int N,p,rsum=0;
  vector<int> A(100009);
  cin>>N>>p;
  for(int i=0;i<N;i++){
    cin>>A[i];
    if(i)
      rsum=(rsum+A[i])%p;
  }
  int lsum=A[0]%p;
  int ans=lsum+rsum;
  for(int i=1;i<N-1;i++){
    lsum=(lsum+A[i])%p;
    rsum=((rsum-A[i])%p+p)%p;
    ans=max(ans,lsum+rsum);
  }
  cout<<ans<<endl;
}
