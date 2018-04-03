#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<numeric>
#include<math.h>
#include<iomanip>
#define ld long double
#define ll long long int
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
#define fi(a,b,c) for(int a=b;a<c;a++)
#define fd(a,b,c) for(int a=b;a>c;a--)
using namespace std;

int T,N;
vector<double> K,S;
long double k,s,D;
long double mmin=0;

int main(){
  cin>>T;
  for(int i = 1 ; i <= T ; i++){
    k=0,s=0,D=0,mmin=0;
    cin>>D>>N;
    for(int j = 0; j < N; j++){
      cin>>k>>s;
      mmin=max(mmin,(D-k)/s);
    }
    cout<<fixed<<"Case #"<<i<<": "<<setprecision(10)<<D/mmin<<endl;
  }
}
