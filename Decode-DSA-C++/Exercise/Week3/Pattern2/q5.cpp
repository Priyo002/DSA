#include<iostream>
using namespace std;

int main(){

    int n;
    cout << "Enter your number : ";
    cin >>n;

    int nsp=1;
    int num=1;
    int num1=1;

    for(int m=1;m<=n;m++){
        cout << num1;
        num1++;
    }
    for(int j=1;j<n;j++){
        cout << num1-2;
        num1--;
    }
    cout << endl;

    for(int i=1;i<=n-1;i++){
        
        for(int j=1;j<=n-i;j++){
            cout << num;
            num++;
        }

        for(int l=1;l<=nsp;l++){
            cout << " ";
        }

        for(int h=1;h<=n-i;h++){
            cout << num-1;
            num--;
        }

        nsp+=2;

        cout << endl;
    }

    return 0;
}