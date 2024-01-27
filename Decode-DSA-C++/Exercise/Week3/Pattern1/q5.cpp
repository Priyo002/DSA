#include<iostream>
using namespace std;

int main(){

    int n;
    cout << "Enter your number : ";
    cin >> n;


    for(int i=1;i<=n;i++){

        for(int j=1;j<=i;j++){
        cout << "*";
        }
        cout << endl;
        
    }
    for(int m=n+1;m<2*n;m++){
        for(int k=1;k<=2*n-m;k++){
            cout << "*";
        }
        
        cout << endl;
    }

    return 0;
}