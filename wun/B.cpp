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

int main(){
   int n;
   int a[50][50],max[50];
   cin>>n;
   fi(i,0,n){
      fi(j,0,n){
         cin>>a[i][j];
         max[i]=max(max[i],a[i][j]);
      }
   }
   int b=1;
   fi(i,0,n){
      if(b&&max[i]==n-1){
         cout<<n<<' ';
         b=0;
         continue;
      }
      cout<<max[i]<<' ';
   }
   cout<<endl;
}

