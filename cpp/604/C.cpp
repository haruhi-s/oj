#include<iostream>
#include<algorithm>
using namespace std;
int n,cnt,f,max;
char t,s[100009],c[100009];
int main(){
   cin>>n>>s;
   if(n==2){cout<<2;return 0;}
   t=s[0];++c[cnt];
   for(int i=1;i<n;i++){
      if(t==s[i])++c[cnt],f++;
      else ++c[++cnt];
      t=s[i];
   }
   if(f==1){cout<<cnt+2;return 0;}

   if(f>1)cout<<cnt+3;
   else cout<<cnt+1;
}

//Qrz Qrz

