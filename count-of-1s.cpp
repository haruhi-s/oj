#include</Users/a-/stdc++.h>
#define ld long double
#define ll long long int
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define fi(a,c) for(int a=0;a<c;a++)
#define isc(a) __int64 a; scanf("%I64d",&a);
#define sc(a) scanf("%I64d",&a)
#define pr(a) printf("%I64d\n",a)
#define ve vector
#define pb push_back
using namespace std;

int countt(int x){
  std::string s;
  do
    {
      s.push_back('0' + (x & 1));
    } while (x >>= 1);
  std::reverse(s.begin(), s.end());
  return count(s.begin(),s.end(),'1');
}
int h(int x){
  int a = x/2;
  int b = x%2;
  int c = b?1:0;
  if (x<1)
    return 0;
  return (b+1)*(countt(a))+c+2*(h(a-1))+a;
}
int countOnes(int l,int r){
  return h(r)-h(l-1);
}

int main(){
  cout<<countOnes(4,7)<<endl;
  return 0;
}
