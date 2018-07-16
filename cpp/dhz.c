#include<stdio.h>

char s[]="hasta la vista, baby";
void swap(int a,int b){
  s[a]^=s[b]^=(s[a]^=s[b]);
}
void inv(int a,int b){
  for(int i=0;i<(b-a)/2;i++)
    swap(a+i,b-i-1);
}
void dhz(){
  inv(0,sizeof(s)-1);
  int anc=0;
  for(int i=0;i<sizeof(s);i++){
    if(s[i]==' '||s[i]==0||s[i]==','){
      inv(anc,i);
      anc=i+1;
    }
  }
}
int main(){
  printf("%lu\n",sizeof(s));
  dhz();
  printf("%s\n",s);
}
