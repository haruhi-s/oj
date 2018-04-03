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

class Graph{
   int v,e;
   vector<int>* a;
   public:
   void G(int vec){
      vector<vector<int> > a(vec);
   }
   void ae(int i,int j){
      a[i].push_back(j);
      a[j].push_back(i);
   }
   int V(){
      return v;
   }
   int E(){
      return e;
   }
};

int main(){
   Graph G;
   G.G(2);
   G.ae(1,0);
   cout<<"f";
   return 0;
}

