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
class p{
   public:
      p(int a,int b,int c):first(a),second(b),third(c){}
      int first;
      int second;
      int third;
      bool operator < (const p &m)const {
         return first < m.first;
      }
};
int main(){
   int n,tx,ty;
   vector< p > coords;
   cin>>n;
   fi(i,0,n){
      cin>>tx>>ty;
      p t(tx,ty,i+1);
      coords.push_back(t);
   }
   sort(coords.begin(),coords.end());
   fi(j,0,n-2){
      if((coords[j].second==coords[j+1].second&&coords[j+2].second==coords[j+1].second)||(coords[j].first==coords[j+1].first&&coords[j+2].first==coords[j+1].first)){
         continue;
      }
      fi(i,0,3){
         cout<<coords[j+i].third<<' ';
      }
      break;
   }
}

