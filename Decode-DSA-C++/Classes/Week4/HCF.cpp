#include<iostream>
using namespace std;

//HCF --> Highest Common Factor

int gcd(int a, int b){
    int hcf;
    for(int i=min(a,b);i>=1;i--){
        if(a%i==0 && b%i==0){ 
            hcf=i; 
            break;
        }
        
    }   
    return hcf;
}

int main(){

    int n,m;
    cout << "Enter your numbers : ";
    cin >> n >> m;

    cout << gcd(n,m);

    return 0;
}