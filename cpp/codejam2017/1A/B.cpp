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

int t,n,p;
vector<int> r;
vector<vector<int> > P;
int temp;
vector<int> tempv;

int main(){
  cin>>t;
  for(int i=1;i<=t;i++){
    r.clear();
    cin>>n>>p;
    for(int j=1;j<=n;j++){
      cin>>temp;
      r.push_back(temp);
    }
    for(int j=1;j<=n;j++){
      tempv.clear();
      for(int k=1;k<=p;k++){
        cin>>temp;
        tempv.push_back(temp);
      }
      sort(tempv.begin(),tempv.end());
      P.push_back(tempv);
    }

  }
}
