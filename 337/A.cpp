#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<numeric>
#define ll long long int
using namespace std;
int n;
int main(){
   cin>>n;
   if(n%2){
      cout<<0<<endl;
      return 0;
   }
   n>>=1;
   if(n%2){
      cout<<n/2<<endl;
      return 0;
   }else{
      cout<<n/2-1<<endl;
      return 0;
   }
}

