#include<iostream>
#include<stdio.h>
#include<algorithm>
#define max(a,b) a>b?a:b
using namespace std;
double m[5];
double w[5];
double hs,hu;
double r;
int main(){
   cin>>m[0]>>m[1]>>m[2]>>m[3]>>m[4];
   cin>>w[0]>>w[1]>>w[2]>>w[3]>>w[4];
   cin>>hs>>hu;
   for(int i=0;i<5;++i){
      r+=max(.3*(i+1)*500,(1.-m[i]/250.)*500.*(i+1)-50.*w[i]);
   }
   r+=hs*100;
   r-=hu*50;
   cout<<r;
}
