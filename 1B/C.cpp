#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<numeric>
#include<math.h>
#define ld long double
#define ll long long int
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
#define fi(a,b,c) for(int a=b;a<c;a++)
#define fd(a,b,c) for(int a=b;a>c;a--)
using namespace std;

int get()
{
  char c;
  while(c=getchar(),(c<'0'||c>'9')&&(c!='-'));
  bool flag=(c=='-');
  if(flag)
    c=getchar();
  int x=0;
  while(c>='0'&&c<='9')
    {
      x=x*10+c-48;
      c=getchar();
    }
  return flag?-x:x;
}

void output(int x)
{
  if(x<0)
    {
      putchar('-');
      x=-x;
    }
  int len=0,data[10];
  while(x)
    {
      data[len++]=x%10;
      x/=10;
    }
  if(!len)
    data[len++]=0;
  while(len--)
    putchar(data[len]+48);
  putchar('\n');
}

vector<string> t1,t2;
map<string,int> c1,c2;
vector<pair<string, string> > topic;
int main(){
   int totaltest=get();
   string temp1,temp2;
   for(int test=1;test<=totaltest;test++){
      t1.clear();t2.clear();c1.clear();c2.clear();topic.clear();
      //init

      int topics=get();
      for(int top=0;top<topics;top++){
         cin>>temp1;cin>>temp2;
         topic.push_back(pair<string,string>(temp1,temp2));
      }
      
   }
}

