#include<stdio.h>

void put_in_array(int *x, int n, int len);
int get_len(int i);

int main(){
  int n,len,sum = 0;
  scanf("%d",&n);
  for(int i = 1; i <= n; i++){
    len = get_len(i);
    int x[len];
    put_in_array(x,i,len);
    for(int j = 0; j < len; j++){
      if(x[j] == 9)
        sum++;
    }
  }
  printf("%d",sum);
  return 0;
}

int get_len(int n){
  int len = 0;
  while(n > 0){
    n /= 10;
    len ++;
  }
  return len;
}

void put_in_array(int *x, int n, int len){
  int div = 1;
  for(int k = 1; k < len; k++){
    div *= 10;
  }
  for(int i = 0; i < len; i++){
    x[i] = n / div;
    n = n % div;
    div /= 10;
  }
}
