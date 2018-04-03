#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#define ll long long int
using namespace std;
int res=0;
int main(){
   for(int i=1;i<=100;i++){
      for(int j=1;j<=100;j++){
         if(max(60,min(i,j))==min(max(60,i),j)){
            cout<<i<<','<<j<<endl;
            cout<<"max(60,min(i,j)) is "<<max(60,min(i,j))<<endl;
            cout<<"min(max(60,i),j) is "<<min(max(60,i),j)<<endl;
            res++;
         }
      }
   }
   cout<<res;
}

