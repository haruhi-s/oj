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
int n,b,p;
int hob (int num)
{
   if (!num)
   return 0;
   int ret = 1;
   while (num >>= 1)ret <<= 1;
   return ret>>1;
}
int x,y;
int main(){
   cin>>n>>b>>p;
   y=p*n;
   while(n>1){
      x+=hob(n)*((b<<1)+1);
      n-=(hob(n));
   }
   cout<<x<<' '<<y;
}

