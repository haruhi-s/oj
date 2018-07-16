#include<bits/stdc++.h>

using namespace std;
vector<int> s(100010);
vector<int> e(100010);
  
bool c(int a,int b){
  if(e[a]==e[b])
    return s[a]>s[b];
  else
    return e[a]<e[b];
}
int main(){
  int t;
  vector<int> I(100010);
  iota(I.begin(),I.end(),0);
  cin>>t;
  for(int i=0;i<t;i++){
    cin>>s[i]>>e[i];
  }
  sort(I.begin(),I.begin()+t,c);
  int last=0,cnt=0;
  for(int i=0;i<t;i++){
    if(s[I[i]]>=last){
      cnt++;last=e[I[i]]+1;
      // cout<<s[I[i]]<<" "<<e[I[i]]<<endl;
    }
  }
  cout<<cnt<<endl;
}
