#include<iostream>
using namespace std;

void display(int a[],int n){
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

// *b --> b[] 

void change(int *b){
    b[0]= 100;
}

int main(){
    int arr[] = {1,4,2,7,4};
    int n = sizeof(arr)/sizeof(int);
    display(arr,n);
    change(arr);
    display(arr,n);

    return 0;
}