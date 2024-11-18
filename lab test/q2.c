#include<stdio.h>
int main(){
    int n,a[30],min,max,i;
    printf("Enter the Value = ");
    scanf("%d",&n);
    printf("Enter %d integer Numbers = ",n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n;i++){
        max=max>a[i]? max : a[i];
        min=min<a[i]? min : a[i];
    }
    printf("The highest Number = %d\nThe lowest Number = %d\n",max,min);
    return 0;
}
