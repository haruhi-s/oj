#include<bits/stdc++.h>

using namespace std;

int n,W;
vector<int> w(109),v(109);
vector<int> A(10009,0);
int main(){
  cin>>n>>W;
  for(int i=1;i<=n;i++)
    cin>>w[i]>>v[i];
  A[0]=0;
  for(int Y=1;Y<=W;Y++){
    A[Y]=A[Y-1];
    for(int j=1;j<=n;j++){
      if(w[j]<=Y)
        A[Y]=max(A[Y],v[j]+A[Y-w[j]]);
    }
  }
  cout<<A[W]<<endl;
  return 0;
}
