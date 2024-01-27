#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cout << "Enter rows/cols of the matrix : ";
    cin >> n;

    int a[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j || i+j == n-1){
                cout << a[i][j] << " ";
            }
            else cout << " ";
        }
        cout << endl;
    }
}