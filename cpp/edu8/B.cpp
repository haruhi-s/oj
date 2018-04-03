#include<iostream>
#include<string.h>
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
char b[300009];
int main(){
   cin>>b;
   int l=strlen(b);
   long long int ret=0;
   fi(i,0,l){
      if(0==b[i]%4){
         ret++;
      }
      if(0==(b[i]+10*b[i-1])%4){
         ret+=i;
      }
   }
   cout<<ret;
}

