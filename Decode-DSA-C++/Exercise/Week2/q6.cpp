#include<iostream>
using namespace std;

int main(){

    int n=65;
    while(n<=90){
        cout << (char)n << "-" << n;
        cout << endl;
        n++;
    }
    return 0;
}