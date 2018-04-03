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
int x1,y1,x2,y2,x3,y3;
int main(){
   cin>>x1>>y1>>x2>>y2>>x3>>y3;
   if(x1==x2&x2==x3){
      cout<<1<<endl;
      return 0;
   }
   if(y1==y2&y2==y3){
      cout<<1<<endl;
      return 0;
   }
   if(x1==x2|x2==x3|x1==x3){
      if(y1==y2|y2==y3|y1==y3){
         cout<<2<<endl;
         return 0;
      }
   }
   if(x1==x2){
      if(y3>=max(y1,y2)|y3<=min(y1,y2)){
         cout<<2<<endl;
         return 0;
      }else{
         cout<<3<<endl;
         return 0;
      }
   }
   if(x1==x3){
      if(y2>=max(y1,y3)|y2<=min(y1,y3)){
         cout<<2<<endl;
         return 0;
      }else{
         cout<<3<<endl;
         return 0;
      }
   }
   if(x3==x2){
      if(y1>=max(y3,y2)|y1<=min(y3,y2)){
         cout<<2<<endl;
         return 0;
      }else{
         cout<<3<<endl;
         return 0;
      }
   }
   if(y1==y2){
      if(x3>=max(x1,x2)|x3<=min(x1,x2)){
         cout<<2<<endl;
         return 0;
      }else{
         cout<<3<<endl;
         return 0;
      }
   }
   if(y1==y3){
      if(x2>=max(x1,x3)|x2<=min(x1,x3)){
         cout<<2<<endl;
         return 0;
      }else{
         cout<<3<<endl;
         return 0;
      }
   }
   if(y3==y2){
      if(x1>=max(x3,x2)|x1<=min(x3,x2)){
         cout<<2<<endl;
         return 0;
      }else{
         cout<<3<<endl;
         return 0;
      }
   }
   cout<<3<<endl;
   return 0;
}

