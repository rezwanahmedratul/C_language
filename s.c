#include<iostream>
using namespace std;

int main()
{
    int x;
  
    do
     {
       cin >> x;
        
       for(int i=1;i<=x;i++)
        {
          if (i==x)
            cout << i;
          else
            cout << i <<" ";
        }    
       
       cout << endl;
          
     } while(x != 0);
     
    return 0;
}
