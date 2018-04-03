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
int curr=0,op=0,s[120],ops[10];
int ref[10]={0,6,7,5,4,8,3,2,9,1};
string cha[]={
   "ZERO",
   "ONE",
   "TWO",
   "THREE",
   "FOUR",
   "FIVE",
   "SIX",
   "SEVEN",
   "EIGHT",
   "NINE"
};
//bool ifk(int num){
//   for(int i=0;i<cha[num].length();i++){
 //     chars[cha[num][i]]--;
//      for(int j=0;j<120;j++){
//         if(chars[j]<0){
//            chars[cha[num][i]]++;
 //           return false;
  //       }else{
//            chars[cha[num][i]]++;
//            return true;
//         }
//      }
//   }
//   return true;
//}

int main(){
   int totaltest=0;
   cin>>totaltest;
   for(int test=1;test<=totaltest;test++){
      memset(s,0,sizeof(s));
      memset(ops,0,sizeof(ops));
      curr=0;op=0;
      //init

      string in;
      cin>>in;
      for(int i=0;i<in.length();i++){
         s[in[i]]++;
      }//chulishuru

      ops[0]=s['Z'];
      s['Z']-=ops[0];
      s['E']-=ops[0];
      s['R']-=ops[0];
      s['O']-=ops[0];

      ops[6]=s['X'];
      s['S']-=ops[6];
      s['I']-=ops[6];
      s['X']-=ops[6];

      ops[7]=s['S'];
      s['S']-=ops[7];
      s['E']-=2*ops[7];
      s['V']-=ops[7];
      s['N']-=ops[7];
      
      ops[5]=s['V'];
      s['F']-=ops[5];
      s['I']-=ops[5];
      s['V']-=ops[5];
      s['E']-=ops[5];

      ops[4]=s['F'];
      s['F']-=ops[4];
      s['O']-=ops[4];
      s['U']-=ops[4];
      s['R']-=ops[4];

      ops[8]=s['G'];
      s['E']-=ops[8];
      s['I']-=ops[8];
      s['G']-=ops[8];
      s['H']-=ops[8];
      s['T']-=ops[8];

      ops[3]=s['R'];
      s['E']-=ops[3];
      s['E']-=ops[3];
      s['T']-=ops[3];
      s['R']-=ops[3];
      s['H']-=ops[3];
      ops[2]=s['T'];
      s['T']-=ops[2];
      s['W']-=ops[2];
      s['O']-=ops[2];
      ops[9]=s['I'];
      s['E']-=ops[9];
      s['N']-=ops[9];
      s['I']-=ops[9];
      s['N']-=ops[9];
      ops[1]=s['O'];
      s['O']-=ops[1];
      s['N']-=ops[1];
      s['E']-=ops[1];

      cout<<"Case #"<<test<<": ";
      for(int i=0;i<10;i++){
         for(int j=0;j<ops[i];j++){
            cout<<i;
         }
      }
      cout<<endl;
   }
   return 0;
}

