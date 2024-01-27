#include<iostream>
using namespace std;

int main(){

    int n;
    cout << "Enter your number : ";
    cin >>n;

    //Method 1

    for(int i=1;i<=n;i++){
        for(int s=1;s<=n-i;s++){
            cout << " ";
        }
        for(int j=1;j<=2*i-1;j++){
        cout << "*";
        }
        cout << endl;

    }
    int m=2*n-1;
    for(int i=n+1;i<=2*n-1;i++){
        for(int s=1;s<=i-n;s++){
            cout << " ";
        }
        for(int j=1;j<m;j++){
        cout << "*";
        }
        m-=2;
        cout << endl;

    }

    //Method 2

    /*int nsp = n-1;
    int nst = 1;

    for(int i=1;i<=2*n-1;i++){

        //Spaces
        for(int j=1;j<=nsp;j++){
            cout << " ";
        }
        if(i<=n-1) nsp --;
        else nsp++;

        //Stars
        for(int k=1;k<=nst;k++){
            cout << "*";
        }
        if(i<=n-1) nst+=2;
        else nst-=2;

        cout << endl;

    }*/



    return 0;
}
