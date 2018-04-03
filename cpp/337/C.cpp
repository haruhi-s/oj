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
int k,t;
int main(){
   cin>>k;
   for(int i=0;(i>>k)==0;i++){
      for(int j=0;(j>>k)==0;j++){
         t=0;
         for(int f=0;f<k;f++){
            t^=((i>>f)&1)&((j>>f)&1);
         }
         cout<<(t?'*':'+');
      }
      cout<<endl;
   }
}

