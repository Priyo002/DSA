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

    int max = a[0];
    for(int i=0;i<n;i++){
        if(a[i]>max) max = a[i];
    }
    int max2 = a[0];
    for(int j=0;j<n;j++){
        if((a[j]>max2) && (a[j] != max)){
            max2 = a[j];
        }
    }
    cout << max2;
}