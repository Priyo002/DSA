#include<iostream>
using namespace std;

int main(){

    int n;
    cout << "Enter your number : ";
    cin >> n;

    int nsp=n;
    int nsp1=1;
    int nsp2=n+1;
    int nsp3=3;

    for(int i=2;i<=n;i++){

        for(int k=1;k<=nsp-1;k++) cout << " ";
        nsp-=2;
        cout << "*";

        for(int l=1;l<=nsp3;l++) cout << " ";
        cout << "*";
        nsp3+=2;
            
        cout << endl;
    }
    
    for(int i=n+1;i<2*n-1;i++){
        for(int j=1;j<=nsp1;j++){
            cout << " ";
        }
        nsp1+=2;
        cout << "*";
        for(int k=1;k<=nsp2;k++){
            cout << " ";
        }
        nsp2-=2;
        cout << "*";

        cout << endl;
    }

    return 0;
}