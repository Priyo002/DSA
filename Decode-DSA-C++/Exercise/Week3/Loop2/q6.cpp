#include<iostream>
using namespace std;

int main(){

    int n;
    cout << "Enter your number : ";
    cin >> n;

    int a = n;

    int sum=0;

    while(n!=0){
        int r = n%10;
        sum = sum *10 + r;
        n/=10;
    }

    cout << "Answer is " << a + sum;
    return 0;
}