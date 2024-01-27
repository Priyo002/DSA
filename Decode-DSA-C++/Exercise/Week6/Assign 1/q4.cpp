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

   int max = INT_MIN;
   for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        if(a[i][j]>max){
            max = a[i][j];
        }
    }
   }
   
   cout << max;
    
    return 0;
}