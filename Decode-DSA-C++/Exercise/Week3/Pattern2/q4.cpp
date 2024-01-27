#include<iostream>
using namespace std;

int main(){

    int n;
    cout << "Enter your number : ";
    cin >>n;

    int nsp=1;
    char alpha='A';

    for(int t=1;t<=2*n-1;t++){
        cout << alpha;
        alpha++;
    }
    cout << endl;
    for(int i=1;i<=n-1;i++){
        
        char k='A';
        for(int j=1;j<=n-i;j++){
            cout << k;
            k++;
        }
        char p=k;
        
        for(int l=1;l<=nsp;l++){
            cout << " ";
        }

        for(int h=1;h<=n-i;h++){
            cout << (char)(p+nsp);
            p++;
        }

        nsp+=2;

        cout << endl;
    
    
    }

    return 0;
}