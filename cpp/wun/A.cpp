#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<numeric>
#define ll long long int
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
#define fi(a,b,c) for(int a=b;a<c;a++)
#define fd(a,b,c) for(int a=b;a>c;a--)
using namespace std;

int main(){
   int A;
   cin>>A;
   fd(i,20,-1){
      if(A&1<<i){
         cout<<i+1<<' ';
      }
   }
   cout<<endl;
}

