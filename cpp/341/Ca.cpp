#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<numeric>
#include<iomanip>
#define ll long long int
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
#define fi(a,b,c) for(int a=b;a<c;a++)
#define fd(a,b,c) for(int a=b;a>c;a--)
using namespace std;
;
int n,p,l[100009],r[100009],ran,ifp;
double prob(int l, int r){
   ran=1+r-l;
   ifp=r/p-l/p;
   //cout<<"ifp is "<<ifp<<endl;
   if((l%p)==0)ifp++;
   //cout<<(double)ifp/(double)ran<<endl;
   return (double)ifp/(double)ran;
}
int main(){
   double exp=0.0;
   cin>>n>>p;
   fi(i,0,n){
      cin>>l[i]>>r[i];
   }
   fi(i,0,n){
      exp+=(1.0-(1.0-prob(l[i],r[i]))*(1.0-prob(l[(i+1)%n],r[(i+1)%n])));
   }
   cout<<std::setprecision(13)<<exp*2000.0;
}

