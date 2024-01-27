#include<iostream>
using namespace std;

int main(){

    int n;
    cout << "Enter your number : ";
    cin >> n;

    for(int i=1;i<=n;i++){
        int k=1;
        for(int j=1;j<=i;j++){
            cout << k;
            k+=2;
        }
        cout << endl;
    }

    return 0;

}