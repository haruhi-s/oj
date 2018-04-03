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
ll t,k,cnt;
string s;
ll flag;

int main(){
  cin>>t;
  fi(i,0,t){
    cin>>s>>k;cnt=0;flag=0;
    for(int j=0;j<=s.length()-k;j++){
      if(s[j]=='-'){
        cnt++;
        fi(l,j,j+k)
          s[l]=s[l]=='+'?'-':'+';
      }else continue;
    }
    for(int j=s.length()-k;j<s.length();j++){
      if(s[j]=='-')flag=1;
    }
    if(flag)
      cout<<"Case #"<<i+1<<": "<<"IMPOSSIBLE"<<endl;
    else
      cout<<"Case #"<<i+1<<": "<<cnt<<endl;
  }
  return 0;
}
