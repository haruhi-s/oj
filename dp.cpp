#include</Users/a-/stdc++.h>

using namespace std;

int main(){
  int n,maxd=1;
  cin>>n;
  vector<int> s(n);
  vector<int> dp(n,1);
  for(int i=0;i<n;i++)
    cin>>s[i];
  for(int i=1;i<n;i++){
    for(int j=i-1;j>=0;j--){
      if(s[j]<=s[i])
        dp[i]=max(dp[i],dp[j]+1),maxd=max(maxd,dp[i]);
      else
        continue;
    }
  }
  cout<<"dp[] is: ";
  for(int i=0;i<n;i++)
    cout<<dp[i]<<' ';
  cout<<endl;
  cout<<"length of max non-decreasing sub-sequence: "<<maxd<<endl;
  return 0;
}
