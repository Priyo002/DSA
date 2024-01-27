#include<bits/stdc++.h>
using namespace std;

int main(){

    int m,n;
    cout << "Enter rows : ";
    cin >> m ;
    cout << endl;
    cout << "Enter columns : ";
    cin >> n;
    cout << endl;

    int arr[m][n];
    int sum = 0;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }

    cout << endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            sum += arr[i][j];
        }
    }

    cout << "Sum of the elements is " << sum;
    
}