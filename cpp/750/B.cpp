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
  int n,t,NS=0,flag=1;
  string s;
  cin>>n;
  fi(i,0,n){
    cin>>t>>s;
    if((NS==0) && (s != "South")){flag=0;break;}
    if((NS==20000) && (s != "North")){flag=0;break;}
    if(!(NS<=20000 && NS>=0)){flag=0;break;}
    if(s=="South") NS+=t;
    if(s=="North") NS-=t;
  }
  if(NS!=0) flag=0;
  cout<<(flag?"YES":"NO")<<endl;
  return 0;
}

