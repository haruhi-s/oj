#include<iostream>
#include<vector>
#define ld long double
#define ll long long int
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define fi(a,b,c) for(int a=b;a<c;a++)
#define fd(a,b,c) for(int a=b;a>c;a--)
#define isc(a) __int64 a; scanf("%I64d",&a);
#define sc(a) scanf("%I64d",&a)
#define pr(a) printf("%I64d\n",a)
using namespace std;

int main(){
   int x=4,y=1;
   int xcnt=0,ycnt=0;
   vector<int> a(10000);
   for(int i=1;i<10000;i++) cin>>a[i];
   for(int i=1;i<10000;i++) {
      a[i]?(x*=2):(x=1);
      a[i]?(y=1):(y*=2);
      if(x==16)x=4,y=1,xcnt++;
      if(y==16)x=4,y=1,ycnt++;
   }
   cout<<endl<<xcnt<<' '<<ycnt<<endl;

}

