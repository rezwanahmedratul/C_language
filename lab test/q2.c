#include<stdio.h>
int main(){
    int n,a[30],min,max,i;
    printf("Enter the Value = ");
    scanf("%d",&n);
    printf("Enter %d integer Numbers = ",n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n-1;i++){
        max=a[i]>a[i+1]? a[i] : a[i+1];
        min=a[i]<a[i+1]? a[i] : a[i+1];
    }
    printf("The highest Number = %d\nThe lowest Number = %d\n",max,min);
    return 0;
}
