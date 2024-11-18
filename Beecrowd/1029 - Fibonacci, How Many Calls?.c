#include<stdio.h>

int call=0;
int fib(int x){
    call++;
    if(x==0) return 0;
    else if(x==1) return 1;
    else return (fib(x-1)+fib(x-2));
}

int main()
{
    int t,fib(int);
    scanf("%d",&t);
   
    while(t--){
        int n,fibn;
        scanf("%d",&n);
        call=0;
        fibn=fib(n);
        printf("fib(%d) = %d calls = %d\n",n,call-1,fibn);
    }
    return 0;
}
