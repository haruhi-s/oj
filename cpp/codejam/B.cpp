#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<numeric>
#include<math.h>
#include<string>
#define ld long double
#define ll long long int
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
#define fi(a,b,c) for(int a=b;a<c;a++)
#define fd(a,b,c) for(int a=b;a>c;a--)
using namespace std;

int main(){
   int n=0;
   string s;
   cin>>n;
   char temp;
   int count=0;
   for(int i=0;i<n;i++){
      cin>>s;
      count=0;
      temp = s[0];
      for(int j=0;j<s.size();j++){
         if(s[j]!=temp){
            count++;
         }
         temp=s[j];
      }
      if(temp=='-')count++;
      cout<<"Case #"<<i+1<<": "<<count<<endl;
   }
   return 0;
}

