#include<iostream>
using namespace std;

int main(){

    int a,b;
    cout << "Enter your numbers : ";
    int *p = &a, *q=&b;
    cin >> *p>> *q;

    cout << *p + *q << endl;
    cout << a+b;

   

    return 0;
}