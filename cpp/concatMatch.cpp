#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
  int n,m;
  string target;
  vector<string> pieces;
  cin>>n>>m;
  cin>>target;
  string temp;
  for(int i = 0; i < m; i++){
    cin>>temp;
    pieces.push_back(temp);
  }
  vector<bool> visited(m,false);
}
