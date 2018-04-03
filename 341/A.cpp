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
int n;
ll sum=0,a[100009];
int main(){
   cin>>n;
   fi(i,0,n){
      cin>>a[i];
      sum+=a[i];
   }
   sort(a,a+n);
   if(!(sum%2)){
      cout<<sum<<endl;
      return 0;
   }else{
      fi(i,0,n){
         if(a[i]%2){
            cout<<sum-a[i]<<endl;
            return 0;
         }
      }
   }
}
