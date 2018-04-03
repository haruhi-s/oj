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
int n,x,y;
vector<int> adj[200009];
bool marked[200009];
void dfs(int p){
   marked[p]=true;
   fi(i,0,adj[p].size()){
      if(!marked[p])dfs(adj[p][i]);
   }
}
int main(){
   cin>>n>>x>>y;
   int t1,t2;
   fi(i,0,n-1){
      cin>>t1>>t2;
      adj[t1].push_back(t2);
      adj[t2].push_back(t1);
   }
   if(x>=y){
      cout<<(n-1)*y<<endl;
      return 0;
   }else{

   }
}

