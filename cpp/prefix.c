prefix(char*a,char*b,char*r){for(;*a&&*a^*b;b++)*r++=*a++;}
char r[10];
int main(){
  char*a="12341234",*b="1231234";
  prefix(a,b,r);
  printf("%s", r);
}
