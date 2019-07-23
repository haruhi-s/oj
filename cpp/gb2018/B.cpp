#include<bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
  ll n;
  ll X=0,Y=0,tx,ty;
  cin >> n;
  for (int i = 0; i < 2*n ; i++){
    cin>>tx>>ty;
    X+=tx;Y+=ty;
  }
  cout<<X/n<<" "<<Y/n<<endl;
}
