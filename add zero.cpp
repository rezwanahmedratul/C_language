#include<iostream>
using namespace std;

int main()
{
    int c,i,t,j,n;
    cin >> t;
    
    for(c=1;c<=t;c++){
      cin >> n;
      j=n;
        {
          int a[n];
          for(i=0;i<=n-1;i++)
            cin >> a[i];
           
          for(i=n-1;i>0;i--) { 
            if(a[i]==j-i){
              j+=i;
              cout << i << endl;
              cout << j << endl;
              i=n-1;
            }
          }  
          cout << j << endl;   
        }
    }
    
    return 0;
}