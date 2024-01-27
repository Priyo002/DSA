#include<iostream>
using namespace std;

//Pass by reference

void swap(int *a,int *b){
    int temp = *a;
    *a=*b;
    *b=temp;
}

int main(){

    int a,b;
    cout << "Enter your numbers : ";
    cin >> a>> b;
    swap(&a,&b);
    cout << a << " " << b;

    return 0;
}