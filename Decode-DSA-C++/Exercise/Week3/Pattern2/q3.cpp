#include<iostream>
using namespace std;

int main(){

    int n;
    cout << "Enter your number : ";
    cin >>n;

    for(int i=1;i<=n;i++){

        for(int s=1;s<=n-i;s++) cout << " ";

        int m = 65+i-1;
        for(int h=1;h<=i-1;h++){
            cout << (char)m;
            m--;
        }
        
        char k='A';
        for(int j=1;j<=i;j++){
            cout << k;
            k++;
        }
        cout << endl;
    }

    return 0;
}