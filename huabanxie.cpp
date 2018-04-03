#include<algorithm>
#include<iostream>
using namespace std;
int m,n;
int c(int r,int m,int n){
   if(n==0||m==0)return 1;
   int sum=0;
   for(int i=0;i<=r;i++){
      sum+=c(r-i+1,m-1,n-i);
   }
   return sum;
}
int main(){
   cin>>m>>n;
   if(m<n){cout<<0<<endl;return 0;}
   cout<<c(0,m,n);
}
