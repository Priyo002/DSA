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

    //Transpose Matrix
    int t[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            t[i][j] = a[j][i];
        }
    }
    cout << endl;
    //Reverse the cols of Transpose Matrix
    for(int j=0;j<n;j++){
        for(int i=0;i<n/2;i++){
            swap(t[i][j],t[n-i-1][j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << t[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}