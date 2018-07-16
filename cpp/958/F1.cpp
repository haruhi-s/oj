#include<bits/stdc++.h>
#define fi(i,s,e) for(int i=0;i<e;++i)

using namespace std;

int main(){
  int n,m;
  vector<int> c(109),k(109);
  cin>>n>>m;
  fi(i,0,n)
    cin>>c[i];
  int ksum=0,mm=0;
  fi(i,0,m){
    cin>>k[i+1];
    if(!k[i+1])mm++;
    ksum+=k[i+1];
  }
  fi(i,0,ksum){
    if(k[c[i]]==0)mm--;
    if(k[c[i]]==1)mm++;
    k[c[i]]--;
  }
  if(mm==m){
    cout<<"YES"<<endl;return 0;
  }
  fi(i,0,n-ksum){
    if(k[c[i]]==-1)mm++;
    if(k[c[i]]==0)mm--;
    k[c[i]]++;
    if(k[c[i+ksum]]==1)mm++;
    if(k[c[i+ksum]]==0)mm--;
    k[c[i+ksum]]--;
    if(mm==m){cout<<"YES"<<endl;return 0;}
  }
  cout<<"NO"<<endl;return 0;
}
