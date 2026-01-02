/*本代码无法实现功能，但我懒得改了，所以就这样吧
* 其实还是可以实现加法的喵  */


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
  int len_1,len_2;
  char a[100] = {0};
  char b[100] = {0};
  char c[100] = {0};
  fgets(a,sizeof(a),stdin);
  a[strcspn(a,"\n")] = '\0';
  fgets(b,sizeof(b),stdin);
  b[strcspn(b,"\n")] = '\0';
  int len_a = strlen(a);
  int len_b = strlen(b);
  if(len_a > len_b){
    len_1 = len_a;
    len_2 = len_b;
  } 
  else{
    len_1 = len_b;
    len_2 = len_a;
  }
  int carry = 0;
  int index = 0;
  for(int i = len_a -1, j = len_b - 1; i >= 0 || j >= 0 || carry != 0; i--, j--){
    int num_a = 0;
    if(i >= 0){
      num_a = a[i] - '0';
    }
    int num_b = 0;
    if(j >= 0){
      num_b = b[j] - '0';
    }
    int sum = num_a + num_b + carry;
    carry = sum / 10;
    sum = sum % 10;
    c[index] = sum + '0';
    index++;
  }
  for(int i = index - 1; i >= 0; i--){
    printf("%c",c[i]);
  }
  return 0;
}
