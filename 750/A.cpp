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
  int n,k;
  cin>>n>>k;
  k=240-k;
  k/=5;
  int sum=0,res;
  for(int i=0;i<=k;i++){
    sum+=i;
    if(sum<=k)res=i;
    else break;
  }
  cout<<min(n,res)<<endl;
  return 0;
}

