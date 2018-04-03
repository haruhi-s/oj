#include</Users/a-/stdc++.h>
#define ld long double
#define ll long long int
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define fi(a,c) for(int a=0;a<c;a++)
#define isc(a) __int64 a; scanf("%I64d",&a);
#define sc(a) scanf("%I64d",&a)
#define pr(a) printf("%I64d\n",a)
#define ve vector
#define pb push_back
using namespace std;

ve<ve<int> > ma;
int main(){
  int n,m,t;
  cin>>n>>m;
  fi(i,n){
    ma.pb(ve<int>());
    fi(j,m){
      cin>>t;
      ma[i].pb(t);
    }
  }
  ve<int> rs,cs;
  fi(i,n){
    t=0;
    fi(j,m)t+=ma[i][j];
    rs.pb(t);
  }
  fi(j,m){
    t=0;
    fi(i,n)t+=ma[i][j];
    cs.pb(t);
  }

  ve<string> ans;
  string tmp;
  if ((*max_element(cs.begin(),cs.end())) > *max_element(rs.begin(),rs.end())) {
    tm -= m;
  }
}

