#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<numeric>
#include<math.h>
#include<sstream>
#define ld long double
#define ll long long int
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
#define fi(a,b,c) for(int a=b;a<c;a++)
#define fd(a,b,c) for(int a=b;a>c;a--)
using namespace std;
int fi,se;
int main(){
   int N,M;
   cin>>N>>M;
   map<int,vector<pair<int,int> > > sexp,pexp;
   for(int i=1;i<N;i++){
      for(int j=i+1;j<=N;j++){
         sexp[i+j].push_back(pair<int,int>(i,j));
         pexp[i*j].push_back(pair<int,int>(i,j));
      }
   }
   for(int ite=0;ite<M;ite++){
      if(ite%2){                                   //Prod says "I don't know."
         //cout<<"\n\nChecking products.\n";
         for(int i=1;i<=N*N;i++){
            if(pexp[i].size()==1){            //If i and j are the only solution to the Prod, and he still doesn't know, then i and j are not answer. 
               //cout<<"Elimination starts for "<<i<<endl;
               fi=pexp[i][0].first;se=pexp[i][0].second;
               vector<pair<int,int> >::iterator it=sexp[fi+se].begin();
               while(it!=sexp[fi+se].end()){
                  if(*it==pexp[i][0]){
                     it = sexp[fi+se].erase(it);  //Clears Sum's assumption for all pairs of (i,j) in exprs for (i+j)
                     //cout<<fi<<' '<<se<<" Eliminated.\n";
                  }else{
                     ++it;
                  }
               }
               pexp[i].clear();               //Clears this answer.
            }
         }
      }else{                                       //Sum says "I don't know."
         //cout<<"\n\nChecking sums.\n";
         for(int i=1;i<=N+N;i++){
            if(sexp[i].size()==1){            //If i and j are the only solution to the Prod, and he still doesn't know, then i and j are not answer. 
               //cout<<"Elimination starts for "<<i<<endl;
               fi=sexp[i][0].first;se=sexp[i][0].second;
               vector<pair<int,int> >::iterator it=pexp[fi*se].begin();
               while(it!=pexp[fi*se].end()){
                  if(*it==sexp[i][0]){
                     it = pexp[fi*se].erase(it);  //Clears Sum's assumption for all pairs of (i,j) in exprs for (i+j)
                     //cout<<fi<<' '<<se<<" Eliminated.\n";
                  }else{
                     ++it;
                  }
               }
               sexp[i].clear();               //Clears this answer.
            }
         }
      }
   }
   //cout<<"Outputting ans\n";
   int count=0;
   stringstream strm;
   if(M%2){
      for(int i=1;i<=N*N;i++){
         if(pexp[i].size()==1){
            count++;
            strm<<pexp[i][0].first<<' '<<pexp[i][0].second<<endl;
         }
         ////cout<<i<<' '<<pexp[i].size()<<endl;
      }
   }else{
      for(int i=1;i<=N+N;i++){
         if(sexp[i].size()==1){
            count++;
            strm<<sexp[i][0].first<<' '<<sexp[i][0].second<<endl;
         }
         //cout<<i<<' '<<sexp[i].size()<<endl;
      }
   }
   cout<<count<<endl<<strm.str();
   return 0;
}

