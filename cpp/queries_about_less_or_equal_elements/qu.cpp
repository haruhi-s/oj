#include<iostream>
#include<algorithm>
#define mem(a) memset(a,0,sizeof(a))
using namespace std;
int n,m;
int f(int* a,int v,int lo,int hi){
   if(hi==lo||hi==lo+1) {
      if(a[lo]>v) return lo-1;
      if(a[hi]<=v) return hi;
      else return lo;
   }
   if(v>=a[(hi+lo)/2])return f(a,v,(hi+lo)/2,hi);
   else return f(a,v,lo,(hi+lo)/2);
}
int main(){
   cin>>n>>m;
   int a[n],b[m];
   for(int i=0;i<n;i++)a[i]=0;
   for(int i=0;i<m;i++)b[i]=0;
   for(int i=0;i<n;i++)cin>>a[i];
   for(int i=0;i<m;i++)cin>>b[i];
   sort(a,a+n);
   for(int i=0;i<m;i++){
      int r=f(a,b[i],0,n-1);
      cout<<r+1<<' ';
   }
}
