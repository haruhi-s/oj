#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<numeric>
#include<math.h>
#define ld long double
#define ll long long int
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
#define fi(a,b,c) for(int a=b;a<c;a++)
#define fd(a,b,c) for(int a=b;a>c;a--)
using namespace std;
ll N,t,cnt;
ll p10 [19] = {1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000,10000000000,100000000000,1000000000000,10000000000000,100000000000000,1000000000000000,10000000000000000,100000000000000000,1000000000000000000};
int main(){
  cin>>t;
  for(int i=1;i<=t;i++){

    cin>>N;
    for(int j=0;;j++){
      if(N/p10[j+1]==0) break;
      else if((N / p10[j]) % 10 < (N / p10[j+1]) % 10) {
        N = ((N / p10[j+1]) - 1) * p10[j+1];
        N += p10[j+1] - 1;
      }
      else continue;
    }
    cout << "Case #" << i << ": " << N << endl;
  }
}
