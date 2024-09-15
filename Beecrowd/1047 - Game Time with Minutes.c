#include<stdio.h>

int main()
{
    int sm,sh,eh,em,H,M,E,S;
    scanf("%d %d %d %d",&sh,&sm,&eh,&em);
    
    S=sh*60+sm;
    E=eh*60+em;
    
    if(E>S)
       {
          H=(E-S)/60;
          M=(E-S)%60;
          printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n",H,M);
       }
    else
       {
          H=((1440-S)+E)/60;
          M=((1440-S)+E)%60;
          printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n",H,M);
       }
    return 0;
}
