#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 2 ; i < n / 2 ; i++ )
    {
        int a = 0 ,b = 0;
        int j = n - 1;
        for(int q = 2 ; q < i ; q++ )
        {
            if( i % q != 0) a = 1;
        }
        for(int p = 2 ; p < j ; p++ )
        {
            if( j % p != 0) b = 1;
        }
        if(a == 0 && b == 0)
            printf("%d %d",i,j);
    }
    return 0;
}
