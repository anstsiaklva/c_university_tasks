#include "stdio.h"
long long gcd(long long a, long long b){
  while (a && b)
    if (a > b) a %= b;
    else b %= a;
  return a+b;   
}
int main (){
  long long a, b, N;
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);  
  scanf("%lld", &N);
  for (int i = 0; i < N; i++){
    scanf("%lld %lld",&a ,&b);
    printf ("%lld\n", (a / gcd(a,b)) * b);
  }
  return 0;
}
