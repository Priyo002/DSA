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

    bool flag = false;
    
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]==a[j]) flag = true;
        }
    }
    if(flag == true) cout << "Duplicate";
    else cout << "No Duplicate";
    
}