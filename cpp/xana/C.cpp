#include<bits/stdc++.h>

using namespace std;

int n,W;
vector<int> w(109),v(109);
vector<vector<int>> A(109,vector<int>(10009,0));
int main(){
  cin>>n>>W;
  for(int i=1;i<=n;i++)
    cin>>w[i]>>v[i];
  for(int j=1;j<=n;j++){
    for(int Y=0;Y<=W;Y++){
      if(w[j]>Y)
        A[j][Y]=A[j-1][Y];
      else{
        A[j][Y]=max(v[j]+A[j-1][Y-w[j]],A[j-1][Y]);
      }
    }
  }
  cout<<A[n][W]<<endl;
  return 0;
}
