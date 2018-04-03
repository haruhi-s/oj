#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<numeric>
#include<math.h>
#define ld long double
#define ll long long int
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
#define fi(a,b,c) for(int a=b;a<c;a++)
#define fd(a,b,c) for(int a=b;a>c;a--)
using namespace std;
ld x[3];
ld f1(ld a,ld b,ld c){
   return log(a)*pow(b,c);
}
ld f2(ld a,ld b,ld c){
   return log(a)*(c)*(b);
}
map<char,int> mpp;

string outs[9]={
   "x^y^z",
   "x^z^y",
   "(x^y)^z",
   "y^x^z",
   "y^z^x",
   "(y^x)^z",
   "z^x^y",
   "z^y^x",
   "(z^x)^y"
};
int main(){
   mpp['x']=0;
   mpp['y']=1;
   mpp['z']=2;
   cin>>x[0]>>x[1]>>x[2];
   ld max=f1(x[0],x[1],x[2]);
   ld t;
   int maxi;
   fi(i,0,9){
      if(i%3!=2){
         t=f1(x[mpp[outs[i][0]]],x[mpp[outs[i][2]]],x[mpp[outs[i][4]]]);
         if(t>max){
            maxi=i;max=t;
         }
      }else{
         t=f2(x[mpp[outs[i][1]]],x[mpp[outs[i][3]]],x[mpp[outs[i][6]]]);
         if(t>max){
            maxi=i;max=t;
         }
      }
   }
   cout<<outs[maxi];
}
