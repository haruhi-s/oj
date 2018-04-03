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

vector<string> m;
int T,r,c;
string temps;

int main(){
  cin>>T;
  for(int i=1;i<=T;i++){
    m.clear();
    cin>>r>>c;
    fi(j,0,r){
      cin>>temps;
      m.push_back(temps);
    }
    fi(j,1,r)
      fi(k,0,c)
      if(m[j][k]=='?') m[j][k]=m[j-1][k];
    fd(j,r-2,-1)
      fi(k,0,c)
      if(m[j][k]=='?') m[j][k]=m[j+1][k];
    fi(j,1,c)
      fi(k,0,r)
      if(m[k][j]=='?') m[k][j]=m[k][j-1];
    fd(j,c-2,-1)
      fi(k,0,r)
      if(m[k][j]=='?') m[k][j]=m[k][j+1];
    cout<<"Case #"<<i<<":"<<endl;
    fi(j,0,r)
      cout<<m[j]<<endl;
  }
}
