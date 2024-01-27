#include<iostream>
using namespace std;

int main(){

    int n;
    cout << "Enter your number : ";
    cin >>n;

    for(int l=1;l<=2*n-1;l++) 
    cout << "*";

    cout << endl;

    int m=n-1;
    int nsp = 1;

    for(int i=1;i<=m;i++){
        for(int j=1;j<=m-i+1;j++){
            cout << "*";
        }
        for(int s=1;s<=nsp;s++){
            cout << " ";
        }
        nsp+=2;
        for(int j=1;j<=m-i+1;j++){
            cout << "*";
        }
        cout << endl;

    }

    return 0;
}
