#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int s[100009],n,k,r;
int main(){
   cin>>n>>k;
   for(int i=0;i<n;i++)cin>>s[i];
   if(n<=k){cout<<s[n-1];return 0;}
   int f=n-k;
   for(int i=0;i<f;i++){
      r=max(r,s[i]+s[2*f-i-1]);
   }
   for(int i=f;i<n;i++){
      r=max(r,s[i]);
   }
   cout<<r;
}
