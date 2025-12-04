#include<stdio.h>
#include<math.h>

void abc(int *x, int i);

int main(){
  int x[3] = {0};
  for(int i = 100; i < 1000; i++){
    abc(x,i);
    int value = pow(x[0],3) + pow(x[1],3) + pow(x[2],3);
    if(value == i) printf("%d ",i);
  }
  return 0;
}

void abc(int *x, int i){
  x[0] = i / 100;
  x[1] = (i - (x[0] * 100)) / 10;
  x[2] = i - (x[0] * 100) - (x[1] * 10);
}
