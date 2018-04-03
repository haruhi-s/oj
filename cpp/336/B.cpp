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
string a,b;
int ai[200009],bi[200009];
int main(){
   ll r=0;
   cin>>a>>b;
   int d=b.length()-a.length();
   for(int i=0;i<a.length();i++){if(a[i]=='1'){ai[i]=1;}else{ai[i]=0;}}
   for(int i=0;i<b.length();i++){if(b[i]=='1'){bi[i]=1;}else{bi[i]=0;}}
   int te=accumulate(bi,bi+d+1,0);
   for(int i=0;i<a.length();i++){
      if(ai[i]){
         r+=d+1-te;
         //cout<<accumulate(bi+i,bi+i+d+1,0)<<endl;
      }else{
         r+=te;
         //cout<<bi+i,bi+i+d+1,0<<endl;
      }
      te-=bi[i];
      te+=bi[i+d+1];
   }
   cout<<r;
}
