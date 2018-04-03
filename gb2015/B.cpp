#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<numeric>
#define ll long long
#define mmax(a,b) a>b?a:b
using namespace std;
ll a,b,t,a0;
int main(){
   cin>>a>>b;
   for(int i=0;i<62;i++){
      if(a&(ll)1<<i){
         a0=max(a0,i);
      }
   }
}
