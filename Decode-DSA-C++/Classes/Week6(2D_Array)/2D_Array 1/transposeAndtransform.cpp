#include<bits/stdc++.h>
using namespace std;

int main(){

    int m;
    cout << "Enter rows/cols : ";
    cin >> m ;

    int arr[m][m];
    
    cout << "Enter your elements : ";
    //INPUT
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }

    cout << endl;
    //Print
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Transpose Matrix is " << endl;
    //Transpose in the same matrix
    for(int i=0;i<m;i++){
        for(int j=i+1;j<m;j++){
            if(!(i==j)){
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
            }
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }



    
}