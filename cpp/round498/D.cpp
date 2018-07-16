#include <bits/stdc++.h>
#define ll long long
#define FOR(i,a,b) for(int i=a;i<=b;++i)
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  char a[100009],b[100009];
  cin>>n;
  cin>>(a+1);
  cin>>(b+1);
  vector<set<char> > s(50009,set<char>());
  int ans=0;
  if(n%2){
    if(a[n/2+1]!=b[n/2+1])
      ++ans;
  }
  FOR(i,1,n/2){
    s[i].insert(a[i]);
    s[i].insert(a[n-i+1]);
    s[i].insert(b[i]);
    s[i].insert(b[n-i+1]);
    // cout<<i<<" "<<s[i].size()<<" ";
    if(s[i].size()==4){
      ans+=2;
    }
    if(s[i].size()==3){
      if(a[i]==a[n-i+1]// ||b[i]==b[n-i+1]
         )
        ans+=2;
      else
        ++ans;
    }
    if(s[i].size()==2){
      if(((a[i]==a[n-i+1]) && (b[i]==b[n-i+1])) ||
         ((a[i]==b[i]) && (a[n-i+1]==b[n-i+1])) ||
         ((a[i]==b[n-i+1]) && (a[n-i+1]==b[i])))
        {
        }else{
        ++ans;
      }
    }
    // cout<<ans<<endl;
  }
  cout<<ans<<endl;
}
