#include<stdio.h>
int main(){
  int n,m;
  scanf("%d%d",&n,&m);
  int a[n+1];
  for(int i=0;i<m;i++){
    int b;
    scanf("%d",&b);
    ++a[b];
  }
  int min = m;
  for(int i=1;i<n+1;i++){
    if(a[i]<min) min = a[i];
  }
  printf("%d",min);
  return 0;
}
