#include<stdio.h>
#include<math.h>
int main(){
    int n,i;
    long long int sum=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        sum+=pow(2*i-1,3);
    printf("%lld",sum);
    return 0;
}
