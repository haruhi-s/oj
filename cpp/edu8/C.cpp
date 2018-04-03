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
int n,k;
char s[100009];
int main(){
   cin>>n>>k;
   cin>>s;
   int i=0;
   int t=0;
   while(k&&(i<n)){
      if(s[i]<'n'){
         t=min(k,122-s[i]);
         s[i]+=t;
      }else{
         t=min(k,s[i]-97);
         s[i]-=t;
      }
      k-=(int)t;
      i++;
   }
   if(k){
      cout<<-1;return 0;
   }
   cout<<s;
}

