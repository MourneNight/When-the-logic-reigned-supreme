#include<stdio.h>

int main(){
  int n = 24;
  for(int i = 2; i <= 2025;i++)
  {
    n = (n * 24) % 100;
  }
  printf("%d",n);
  return 0;
}
