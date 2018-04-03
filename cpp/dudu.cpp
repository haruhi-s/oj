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

int main(){
   int n;
   n=100;
   while(n<=200){
      if(n%3==0)continue;
      cout<<n<<',';
      n++;
   }
   cout<<endl;
   return 0;
}

