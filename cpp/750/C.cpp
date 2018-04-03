#include<bits/stdc++.h>
#define ld long double
#define ll long long int
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define fi(a,b,c) for(int a=b;a<c;a++)
#define fd(a,b,c) for(int a=b;a>c;a--)
#define isc(a) __int64 a; scanf("%I64d",&a);
#define sc(a) scanf("%I64d",&a)
#define pr(a) printf("%I64d\n",a)
using namespace std;

int main(){
  int n,c[200009],d[200009];
  cin>>n;
  int diff=0;
  fi(i,0,n){
    scanf("%d %d",c+i,d+i);
    diff+=c[i];
  }
  int rmax=200000009,rmin=-200000009;
  int offset=-diff;
  fi(i,0,n){
    // cout<<offset<<endl; //                   test
    if(d[i]==2) rmax=min(rmax,1899-offset);
    if(d[i]==1) rmin=max(rmin,1900-offset);
    offset+=c[i];
  }
  if(rmax==200000009) {
    cout<<"Infinity"<<endl;
    return 0;
  }
  if(rmax<rmin) {
    cout<<"Impossible"<<endl;
    return 0;
  }
  else {
    cout<<rmax<<endl;
    return 0;
  }
}

