#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cout << "Enter no. of rows/cols of Matrix : ";
    cin >> n;

    int a[n][n];
    cout << "Enter the elements of the matrix : ";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i== n/2 || j==n/2){
                cout << a[i][j] <<" ";
            }
            else cout <<" ";
        }
        cout << endl;
    }
    

    
    return 0;
}