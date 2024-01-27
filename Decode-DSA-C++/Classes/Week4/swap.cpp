#include<iostream>
using namespace std;

//Without temp

int main(){

    int a,b;
    cout << "Enter your numbers : ";
    cin >> a>> b;

    a = a+b;
    b = a-b;
    a = a-b;

    cout << a << " " << b;

   

    return 0;
}