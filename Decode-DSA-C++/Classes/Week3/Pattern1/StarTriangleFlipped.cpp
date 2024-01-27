#include<iostream>
using namespace std;

int main(){

    int n;
    cout << "Enter your number : ";
    cin >> n;

    for(int i=1;i<=n;i++){

        for(int space=1;space<=n-i;space++){
            cout << " ";
        }
        for(int star=1;star<=i;star++){
            cout << "*";
        }
        cout << endl;
    }

    return 0;

}