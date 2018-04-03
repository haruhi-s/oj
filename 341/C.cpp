#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<numeric>
#define ll long long int
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
#define fi(a,b,c) for(int a=b;a<c;a++)
#define fd(a,b,c) for(int a=b;a>c;a--)
using namespace std;
int n,p;
int l[100009],r[100009];
double prob(int l,int r){
   if(p>=l&&p<=r){
      cout<<"l::"<<l<<endl<<"p::"<<p<<endl<<"r::"<<r<<endl;
      int ran=1+r-l;
      int ifp=r/p-l/p;
      if(l%p==0)ifp++;
      if(r%p==0)ifp--;
      cout<<"prob is:"<<(double)ifp/(double)ran<<endl;
      return (double)ifp/(double)ran;
   }
   else{
      cout<<"prob is 0.0"<<endl;
      return 0.0;
   }
}
double prob1,prob2;
int main(){
   cin>>n>>p;
   fi(i,0,n){
      cin>>l[i]>>r[i];
   }
   double exp=0.0;
   for(int i=0;i<n;i++){
      cout<<i<<endl;
      prob1=prob(l[i],r[i]);
      prob2=prob(l[(i+1)%n],r[(i+1)%n]);
      exp+=prob1;
      exp+=(1.0-prob1)*prob2;
   }
   exp*=1000.0;
   cout<<exp<<endl;
}

