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

    int min = a[0];
    for(int i=0;i<n;i++){
        if(a[i]<min) min = a[i];
    }

    cout << min;
    
}