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
string s;
int a,b,c,d,res;
stack<char> st;
int main(){
   cin>>s;
   int l=s.length();
   if(l%2){
      cout<<"Impossible"<<endl;
      return 0;
   }
   for(int i=0;i<l;i++){
      switch(s[i]){
         case '(':
            st.push(s[i]);
            ++a;
            break;
         case ')':
            if(st.empty()){
               cout<<"Impossible"<<endl;
               return 0;
            }
            if(st.top()!='(')res++;
            st.pop();
            --a;
            break;
         case '{':
            st.push(s[i]);
            ++b;
            break;
         case '}':
            if(st.empty()){
               cout<<"Impossible"<<endl;
               return 0;
            }
            if(st.top()!='{')res++;
            st.pop();
            --b;
            break;
         case '[':
            st.push(s[i]);
            ++c;
            break;
         case ']':
            if(st.empty()){
               cout<<"Impossible"<<endl;
               return 0;
            }
            if(st.top()!='[')res++;
            st.pop();
            --c;
            break;
         case '<':
            st.push(s[i]);
            ++d;
            break;
         case '>':
            if(st.empty()){
               cout<<"Impossible"<<endl;
               return 0;
            }
            if(st.top()!='<')res++;
            st.pop();
            --d;
            break;
         default:
            ;
      }
   }
   if(a+b+c+d)cout<<"Impossible"<<endl;
   else{
      cout<<res<<endl;
   }
}

