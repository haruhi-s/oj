#include<stack>
#include<numeric>
#include<math.h>
#include<iomanip>
#define ld long double
#define ll long long int
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
#define fi(a,b,c) for(int a=b;a<c;a++)
#define fd(a,b,c) for(int a=b;a>c;a--)
using namespace std;

int T,N;
int R,O,Y,G,B,V;
string s;
int M;

int main(){
  cin>>T;
  for(int i=1;i<=T;i++){
    cin>>N>>R>>O>>Y>>G>>B>>V;
    M=max(R,(max(O,max(Y,(max(G,max(B,V)))))));
    s="";
    if((R+Y)%2!=0 || (R+B)%2!=0 || (B+Y)%2!=0)
      cout<<"Case #"<<i<<": IMPOSSIBLE"<<endl;
    else{
      if(R!=0){
        
      }
    }
  }
}
