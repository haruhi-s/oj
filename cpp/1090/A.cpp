#include<bits/stdc++.h>
#define ll long long int
using namespace std;

struct com{
  ll max;
  ll num;
};

bool comp(com a,com b){
  return(a.max < b.max);
}

int main(){
  int n;
  cin>>n;
  vector<com> c; //max, number of employees
  ll t;

  for(int i=0;i<n;i++){
    c.push_back(com{0,0});
    cin>>c[i].num;

    for(int j=0;j<c[i].num;j++){
      cin>>t;
      t>c[i].max?c[i].max=t:0; //max
    }
  }
  sort(c.begin(),c.end(),comp);

  ll sum = 0;
  for(int i = 0; i < n-1; i++){
    sum += c[i].num*(c[i+1].max - c[i].max);
    c[i+1].num+=c[i].num;
  }
  cout << sum << endl;
}
