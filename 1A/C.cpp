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
int n,N;
int l[1009];
int C[1009];
vector<pair<int, int> > vp2;
vector<int> tempVec;
vector<vector<int> > fo(1009,tempVec);
int getL(int a){
   int L=1;
   int t=a;
   while(l[t]!=a){
      t=l[t];L++;
      if(L>1009){
         return 1;
      }
   }
   if(L==2){
      pair<int,int> tp(l[t],a);
      vp2.push_back(tp);
   }
   return L;
}
int getD(int k,int D){
   queue<int> dfq;
   int Di=D;
   for(int i=0;i<fo[k].size();i++){
      
   }
   return 0;
}
int main(){
   cin>>n;int maxlc;
   for(int i=0;i<n;i++){
      int maxL=0;
      cin>>N;
      for(int j=1;j<=N;j++){
         cin>>l[j];
         fo[l[j]].push_back(j);
      }
      for(int k=1;k<=N;k++){
         maxL=max(maxL,getL(k));
      }
      for(int l=0;l<vp2.size();l++){
         maxlc+=(2+getD(vp2[l].first,0)+getD(vp2[l].second,0));
      }

      int re=max(maxL,maxlc);
      cout<<"Case #"<<i+1<<": "<<   re  <<endl;


   }
}

