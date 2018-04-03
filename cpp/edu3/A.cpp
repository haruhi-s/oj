#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#define ll long long int
using namespace std;
int n,m,a[100],r;
int main(){
   cin>>n>>m;
   for(int i=0;i<n;i++){
      cin>>a[i];
   }
   sort(a,a+n);
   while(m>0){
      m-=a[--n];
      r++;
   }
   cout<<r;
}

