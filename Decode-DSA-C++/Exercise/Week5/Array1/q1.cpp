#include<iostream>
using namespace std;

int main(){

    int n;
    cout << "Enter the size of the array : ";
    cin >> n;

    int a[n];
    cout << "Enter the elements : ";
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    int prod = 1;
    for(int i=0;i<n;i++){
        prod = prod * a[i];
    }
    cout << prod;
}