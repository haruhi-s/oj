#include<bits/stdc++.h>

using namespace std;
int main(){
  int T;
  cin>>T;
  int D,power;
  string s;
  for(int t=1;t<=T;++t){
    cin>>D>>s;
    power=1;int sum=0;
    vector<int> v(1,0);
    for(int i=0;i<s.length();i++){
      if(s[i]=='C'){
        power*=2;
        v.push_back(0);
      }
      if(s[i]=='S'){
        sum+=power;
        ++*(v.end()-1);
      }
    }
    for(int i=v.size()-1;i>0;i--){
      v[i-1]+=v[i];
    }
    //solve
    if(v[0]>D){
      cout<<"Case #"<<t<<": IMPOSSIBLE"<<endl;
      continue;
    }else{
      int d=sum-D;
      int i=v.size()-1,cnt=0;
      power/=2;
      while(1){
        if(d<=0)
          break;
        if(v[i]==0){
          i--;power/=2;
          continue;
        }else{
          v[i]--;cnt++;
          d-=power;
          continue;
        }
      }
      cout<<"Case #"<<t<<": "<<cnt<<endl;
    }
  }
  return 0;
}
