#include<iostream>
#include<algorithm>
#define M 1000000007
#define ll long long int 
using namespace std;
ll p,k,m;
ll r=1;
ll q(ll b,int pow){
   ll ans=1;
   while(pow!=0){
      if(pow&1){
         ans=ans*b%M;
      }
      b=b*b%M;
      pow>>=1;
   }
   return ans;
}
int main(){
   cin>>p>>k;
   if(k==0){
      cout<<q(p,p-1);
      return 0;
   }
   if(k==1){
      cout<<q(p,p);
      return 0;
   }
   ll j=1;
   for(j=k;j!=1;j=j*k%p){m++;}
   m++;
   //for(int i=0;i<(p-1)/m;i++){
   //   r=r*p%M;
   //}
   r=q(p,(p-1)/m);
   cout<<r%M;
}
