#include <bits/stdc++.h>
#define ll long long
#define FOR(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int n;
string temp;
vector<string> patterns;
string text;
vector<pair<int,string*>> results;
struct node{
  char ch;
  bool end;
  string* pattern;
  map<char,node*> next;
  node* partial;
  node(char a){
    ch = a;
    end = 0;
    next=map<char,node*>();  }};
node root('R');
map<char,node*>::iterator srch;
node* tnode = &root;
void dfs(node* n){
  for(auto& m : n->next){
    tnode = m.second;
    srch = n->partial->next.find(tnode->ch);
    if (srch == n->partial->next.end())
      tnode->partial = &root;
    else
      tnode->partial = srch->second;
    dfs(tnode);  }
  return;}
int main(){
  cin>>text;
  cin>>n;
  FOR(i,1,n){
    cin>>temp;
    patterns.push_back(temp);  }
  sort(patterns.begin(),patterns.end());
  root.end=0;
  root.partial=&root;
  node* t;
  map<char,node*> *s;
  for(auto& i : patterns){      // initializes the srch tree
    t = &root;
    for(int j = 0; j < i.length(); j++){
      s = &(*t).next;
      if (s->find(i[j]) == s->end()){
        (*s)[i[j]] = new node(i[j]);
      }
      t = (*s)[i[j]];
      if(j==i.length()-1)
        t->end=1, t->pattern=&i;    }  }
  for(auto& m : root.next){
    m.second->partial = &root;
    dfs(m.second);  }
  t = &root;
  for(int i = 0; i < text.length(); i++){
    if(i)
      cout<<text[i-1]<<' '<<t->ch<<' '<<t->partial->ch<<endl;
    srch = t->next.find(text[i]);
    if(srch != t->next.end()){
      t = srch->second;
    }else{
      t = t->partial;    }
    if(t->end){
      results.push_back(pair<int,string*>(i + 1 - t->pattern->length(), t->pattern));
      --i; continue;   }  }
  for(auto &s : results)
    cout<<s.first<<" "<<*s.second<<endl;
  cout<<endl;
}
