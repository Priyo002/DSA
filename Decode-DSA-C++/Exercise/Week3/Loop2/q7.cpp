#include<iostream>
using namespace std;

void fact(int n){
    int prod = 1;
    for(int i=1;i<=n;i++){
        prod = prod *i;
    }

    cout << prod << endl;
}

int main(){

    int n;
    cout << "Enter your number : ";
    cin >> n;

    for(int i=1;i<=n;i++){
        fact(i);
    }

    //cout << "Answer is " << prod;
    return 0;
}