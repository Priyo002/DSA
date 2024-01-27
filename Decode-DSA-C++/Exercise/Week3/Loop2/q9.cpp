#include <bits/stdc++.h>
using namespace std;


int main( ) {

    
for(int n=1;n<=500;n++){
    int x=0,temp=n;

    while(temp!=0){
        int r=temp%10;
        x=x+(r*r*r);
        temp/=10;

    }
    if(n == x)
    cout << x << endl;
}

   return 0;
}