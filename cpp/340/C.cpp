#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<numeric>
#define ll long long int
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) a>=0?a:-a
using namespace std;

class dis {
   public:
      dis(ll a,ll b):d1(a),d2(b){}
      ll d1,d2;
      bool operator < (const dis &m) const {
         return d1<m.d1;
      }
};
bool lesss(const dis &a, const dis &b){
   return a.d2 < b.d2;
}
ll distance(int x1,int y1,int x2,int y2){
   return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
int n,q1,w1,q2,w2;
int main(){
   vector< dis > v;
   cin>>n>>q1>>w1>>q2>>w2;
   int q[n],w[n];
   ll tmp1,tmp2;

   ll r=0;
   for(int i=0;i<n;i++){
      cin>>q[i]>>w[i];
      tmp1=distance(q1,w1,q[i],w[i]);
      tmp2=distance(q2,w2,q[i],w[i]);
      dis tdis(tmp1,tmp2);
      v.push_back(tdis);
      r=max(r,tmp1);
   }
   cout<<"test1"<<endl;
   for(int i;i<n;i++){
      cout<<v[i].d1<<' '<<v[i].d2<<endl;
   }
   cout<<"test over"<<endl;
   sort(v.begin(),v.end(),lesss);
   vector< dis > v2=v;
   sort(v.begin(),v.end());
   for(int i;i<n;i++){
      cout<<v[i].d1<<' '<<v[i].d2<<endl;
   }
   cout<<"test over"<<endl;
   ll minr=r;
   for(int i=0;i<n;i++){
      minr=min(r,minr);
      r=r-v[i].d1+v[i].d2;
   }
   cout<<r;
}
