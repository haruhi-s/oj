#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  int a;
  cin >> N;

  vector<int> v(N+1,0);
  for (int i = 0; i <= N; ++i) {
    cin >> a;
    if(++v[a]>1){
      cout<<a<<endl;
      return 0;
    }
  }
}
