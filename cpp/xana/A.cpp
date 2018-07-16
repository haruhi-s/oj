#include<bits/stdc++.h>

using namespace std;
int C1,C5,C10,C50,C100,C500,A;
int main(){
  cin>>A>>C1>>C5>>C10>>C50>>C100>>C500;
  int sum=0;
  int temp;
  temp=A/500;
  if(temp<=C500){
    A%=500;
    sum+=temp;
  }else{
    A-=500*C500;
    sum+=C500;
  }
  temp=A/100;
  if(temp<=C100){
    A%=100;
    sum+=temp;
  }else{
    A-=100*C100;
    sum+=C100;
  }
  temp=A/50;
  if(temp<=C50){
    A%=50;
    sum+=temp;
  }else{
    A-=50*C50;
    sum+=C50;
  }
  temp=A/10;
  if(temp<=C10){
    A%=10;
    sum+=temp;
  }else{
    A-=10*C10;
    sum+=C10;
  }
  temp=A/5;
  if(temp<=C5){
    A%=5;
    sum+=temp;
  }else{
    A-=5*C5;
    sum+=C5;
  }
  temp=A/1;
  if(temp<=C1){
    A%=1;
    sum+=temp;
  }else{
    A-=1*C1;
    sum+=C1;
  }
  cout<<sum<<endl;
}
