#include<bits/stdc++.h>
using namespace std;

int main(){

    int m;
    cout << "Enter no. of rows of Matrix : ";
    cin >> m;

    int n;
    cout << "Enter no. of cols of Matrix : ";
    cin >> n;

    int a[m][n];
    cout << "Enter the elements of the matrix : ";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
        }
    }

    int l1,r1;
    cout << "Enter the coordinates : ";
    cin >> l1 >> r1;
    int l2,r2;
    cout << "Enter again : ";
    cin >> l2;
    cin >> r2;
    int sum = 0;
    for(int i=min(l1,l2);i<=max(l1,l2);i++){
        for(int j=min(r1,r2);j<=max(r1,r2);j++){
            sum = sum + a[i][j];
        }
        
    }

    cout << sum;

    
    return 0;
}