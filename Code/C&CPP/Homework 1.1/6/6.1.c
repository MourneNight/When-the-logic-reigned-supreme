#include<stdio.h>

int main(){
  int max,min,temp,GCD,LCM;
  scanf("%d%d",&max,&min);
  if(max < min){
    temp = max;
    max = min;
    min = temp;
  }
  for(int i = min;;i--){
    if(max % i == 0){
      if(min % i == 0){
        GCD = i;
        printf("%d ",i);
        break;
      }
    }
  }
  LCM = (max / GCD) * (min / GCD) * GCD;
  printf("%d",LCM);
  return 0;
}
