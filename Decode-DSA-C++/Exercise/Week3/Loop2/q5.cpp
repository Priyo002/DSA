#include<iostream>
using namespace std;

int main(){

    int n;
    cout << "Enter your number : ";
    cin >> n;

    int sum=0;
    int i;

    while(n!=0){
        int r = n%10;
        if(r%2==0){
            sum+=r;
        }
        n/=10;
    }

    cout << "Answer is " << sum;
    return 0;
}