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
int a[200009],n;
int main(){
   cin>>n;
   ll mi=1000000009;
   for(int i=0;i<n;i++){
      cin>>a[i];
      if(a[i]<mi)mi=a[i];
   }
   ll mm=0,maxmm=0;
   for(int i=0;i<2*n;i++){
      if(a[i%n]!=mi){
         ++mm;
      }else{
         mm=0;
         if(i>=n)break;
      }
      if(mm>maxmm)maxmm=mm;
   }
   ll res=n*mi;
   res+=maxmm;
   cout<<res<<endl;
   return 0;
}

