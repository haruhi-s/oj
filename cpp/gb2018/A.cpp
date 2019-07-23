#include<bits/stdc++.h>
#define ll long long int
using namespace std;


int main(){
  int r,b,y;
  cin >> y >> b >> r;
  cout << min(r-2, min (b-1, y)) *3 +3 <<endl;
  return 0;
}
