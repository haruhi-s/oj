#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<map>
#define ll long long int
#define b(a) max(0,a)
using namespace std;
int a,b,c,x,y,z,ra,rb,rc;
int main(){
   cin>>a>>b>>c>>x>>y>>z;
   ra=(a-x)%2?(a-x)/2+1:(a-x)/2;if(a<x)ra=0;if(ra*2>a)--ra;
   rb=(b-y)%2?(b-y)/2+1:(b-y)/2;if(b<y)rb=0;if(rb*2>b)--rb;
   rc=(c-z)%2?(c-z)/2+1:(c-z)/2;if(c<z)rc=0;if(rc*2>c)--rc;
   a-=ra*2;
   b-=rb*2;
   c-=rc*2;
   //cout<<ra<<' '<<rb<<' '<<rc<<' '<<a<<' '<<b<<' '<<c<<endl;
   int r=ra+rb+rc;
   if(b(x-a)+b(y-b)+b(z-c)<=r&&x-a<=r&&y-b<=r&&z-c<=r){cout<<"Yes"<<endl;return 0;}else{cout<<"No"<<endl;return 0;}
}
