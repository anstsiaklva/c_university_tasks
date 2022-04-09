#include "stdio.h"
int gcd(int a, int b){
  while (a && b)
    if (a > b) a %= b;
    else b %= a;
  return a+b;   
}

int main (){
  int a, b;
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);  
  scanf("%d %d", &a, &b);
  printf("%d", gcd(a, b));
  //printf("%d", a / gcd(a, b) * b);
  return 0;
}
