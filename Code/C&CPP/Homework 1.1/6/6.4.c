#include<stdio.h>

int main(){
  double height = 50,sum = 100.0;
  for(int i = 1; i < 10; i++){
    sum = sum + height * 2;
    height /= 2;
  }
  printf("%.6lf %.6lf",sum,height);
  return 0;
}
