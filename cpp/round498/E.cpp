#include <bits/stdc++.h>
#define ll long long
#define FOR(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
vector<vector<int>> T(200009);
int st[200009];
int st_[200009];
int sz[200009];
int ind=0;
int dfs(int i){
  ind++;
  st[ind]=i;
  st_[i]=ind;
  if(T[i].size()==0){
    sz[i]=1;
    return sz[i];
  }
  for(auto j=T[i].begin();j!=T[i].end();j++){
    sz[i]+=dfs(*j);
  }
  sz[i]++;
  return sz[i];
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n,q;
  cin>>n>>q;
  int t[200009];
  FOR(i,2,n){
    cin>>t[i];
    T[t[i]].push_back(i);
  }
  int u,k;
  dfs(1);
  FOR(i,1,q){
    cin>>u>>k;
    if(sz[u]<k){
      cout<<"-1"<<endl;
    }else{
      cout<<st[st_[u]+k-1]<<endl;
    }
  }
}

