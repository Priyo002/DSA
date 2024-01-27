#include<iostream>
using namespace std;

int main(){

    int n;
    cout << "Enter your number : ";
    cin >>n;

    //Method 1

    /*for(int i=1;i<=n;i++){
        for(int s=1;s<=n-i;s++){
            cout << " ";
        }
        for(int j=1;j<=2*i-1;j++){
        cout << "*";
        }
        cout << endl;
    }*/

    //Method 2 (nst and nsp)

    int nst = 1;    //nst --> no. of stars
    int nsp = n-1;  //nsp --> no. of spaces

    for(int i=1;i<=n;i++){
        //spaces
        for(int j=1;j<=nsp;j++){
            cout << " ";
        }
        nsp--;
        //stars
        for(int k=1;k<=nst;k++){
            cout << "*";
        }
        nst+=2;
        cout << endl;
    }

    return 0;
}



