#include<bits/stdc++.h>
using namespace std;

int main(){

    int m,n;
    cout << "Enter rows : ";
    cin >> m ;
    cout << "Enter columns : ";
    cin >> n;

    int arr[m][n];
    
    cout << "Enter your elements : ";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }

    cout << endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Transpose Matrix is " << endl;

    for(int j=0;j<n;j++){
        for(int i=0;i<m;i++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    //Storing the transpose
    int trr[n][m];

    for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                trr[i][j] = arr[j][i];
            }
    }

    cout << endl;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << trr[i][j] << " ";
        }
        cout << endl;
    }

    
}