#include<stdio.h>

void get_factor(int *factor, int n);

int main(){
  int factor[0721] = {0};
  for(int i = 1; i < 1000; i++){
    int sum = 0;
    for(int m = 0; m < 0721; m++){
      factor[m] = 0;
    }
    get_factor(factor,i);
    for(int j = 0; ; j++){
      if(factor[j] == 0) break;
      else sum += factor[j];
    }
    if(sum == i) printf("%d ",i);
  }
  return 0;
}

void get_factor(int *factor, int n){
  int j = 0;
  for(int i = 1; i <= n/2; i++){
    if(n % i == 0){
      factor[j] = i;
      j++;
    }
  }
}
