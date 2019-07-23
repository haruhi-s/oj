#include <bits/stdc++.h>
#define ll long long
#define FOR(i,a,b) for(int i=a;i<=b;++i)
using namespace std;

string temp;

int n;
vector<string> patterns;
vector<int> partial;
string text;
vector<int> results;

int main(){
  cin>>text;
  cin>>n;
  FOR(i,1,n){
    cin>>temp;
    patterns.push_back(temp);
  }
  partial.push_back(0);
  if(patterns[0].length()>1){
    for(int i = 1, j = 0; i < patterns[0].length(); i++){
      if(patterns[0][i] == patterns[0][j])
        j++;
      else
        j=patterns[0][j]==patterns[0][i]?1:0;
      partial[i]=j;
    }
  }

  for(int i = 0, j = 0; i < text.length(); i++){
    if(text[i] == patterns[0][j]){
      j++;
      if(j == patterns[0].length()){
        results.push_back(i-j+1);
        j=partial[j-1];
      }
    }else{
      j=partial[j];
    }
  }

  cout<<results.size()<<endl;

  for(auto &s : results)
    cout<<s<<" ";
  cout<<endl;
}
