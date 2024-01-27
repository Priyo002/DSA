#include<iostream>
using namespace std;

int main(){

    int n;
    cout << "Enter your number : ";
    cin >>n;

    for(int i=1;i<=n;i++){
        for(int s=1;s<=n-i;s++) cout << " ";
        char k='A';
        for(int j=1;j<=2*i-1;j++){
            cout << k;
            k++;
        }

        cout << endl;
    }

    return 0;
}