#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<numeric>
#include<math.h>
#include<tgmath.h>
#define ll long long int
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
#define fi(a,b,c) for(int a=b;a<c;a++)
#define fd(a,b,c) for(int a=b;a>c;a--)
#define PI 3.14159265
using namespace std;
class p{
   public:
      p(double a,double b,int c):f(a),s(b),ang(c){}
      double f;
      double s;
      int ang;
};
int n,m;
int x,y,z;
vector<p> co;
void op1(int p,int l){
   fi(i,p,n){
      co[i].f+=l*cos(co[p-1].ang *  180 / PI);
      co[i].s+=l*sin(co[p-1].ang *  180 / PI);
   }
}
void op2(int p,int deg){
   co[p-1].ang+=deg;
   fi(i,p,n){
      co[i].ang+=deg;
   }
}
int main(){
   cin>>n>>m;
   fi(i,0,n){
      p tem((double)i,0.0,0);
      co.push_back(tem);
   }
   fi(i,0,m){
      cin>>x>>y>>z;
      if(x==1)op1(y,z);
      //else op2(y,z);
   }
   fi(i,0,n){
      cout<<co[i].f<<' '<<co[i].s<<endl;
   }
}

