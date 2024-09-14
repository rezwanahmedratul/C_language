#include<stdio.h>

int main()
{
    double T;
    int C,t,n100,n50,n20,n10,n5,n2,n1,n_50,n_25,n_10,n_05,n_01;
    scanf("%lf",&T);
    t=T;
    C=(T-t)*100;
    n100=t/100;
    n50=(t%100)/50;
    n20=((t%100)%50)/20;
    n10=(((t%100)%50)%20)/10;
    n5=((((t%100)%50)%20)%10)/5;
    n2=(((((t%100)%50)%20)%10)%5)/2;
    n1=(((((t%100)%50)%20)%10)%5)%2;
    
    n_50=C/50;
    n_25=(C%50)/25;
    n_10=((C%50)%25)/10;
    n_05=(((C%50)%25)%10)/5;
    n_01=(((C%50)%25)%10)%5;
    
    printf("NOTAS:\n%d nota(s) de R$ 100.00\n%d nota(s) de R$ 50.00\n%d nota(s) de R$ 20.00\n%d nota(s) de R$ 10.00\n%d nota(s) de R$ 5.00\n%d nota(s) de R$ 2.00\nMOEDAS:\n%d moeda(s) de R$ 1.00\n%d moeda(s) de R$ 0.50\n%d moeda(s) de R$ 0.25\n%d moeda(s) de R$ 0.10\n%d moeda(s) de R$ 0.05\n%d moeda(s) de R$ 0.01\n",n100,n50,n20,n10,n5,n2,n1,n_50,n_25,n_10,n_05,n_01);
    return 0;
}
