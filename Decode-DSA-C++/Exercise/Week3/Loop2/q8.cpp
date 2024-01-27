#include<iostream>
using namespace std;

int main(){

    int n;
    cout << "Enter your number : ";
    cin >> n;

    int a=1;
    int b=0;
    int sum = 0;

    for(int i=1;i<=n;i++){
        sum = a+b;
        a=b;
        b=sum;

        cout << b << endl;
    }
    
    return 0;
}