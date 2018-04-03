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
int a;
string s;
int main(){
   cin>>a;
   cin>>s;
   cin>>s;
   if(s=="week"){
      if(a==5|a==6){
         cout<<53;
      }else{
         cout<<52;
      }
   }else{
      if(a==31){
         cout<<7;
      }else if(a==30){
         cout<<11;
      }else{
         cout<<12;
      }
   }
}

