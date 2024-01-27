#include<bits/stdc++.h>
using namespace std;

int main(){

    int m;
    cout << "Enter no. of rows of 1st Matrix : ";
    cin >> m;

    int n;
    cout << "Enter no. of cols of 1st Matrix : ";
    cin >> n;

    int a[m][n];
    cout << "Enter the elements 1st matrix : ";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
        }
    }
    int b[m][n];
    cout << "Enter the elements of 2nd matrix : ";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin >> b[i][j];
        }
    }

    int res[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            res[i][j] = a[i][j] + b[i][j];
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}