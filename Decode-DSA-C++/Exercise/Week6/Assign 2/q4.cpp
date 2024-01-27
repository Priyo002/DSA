#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cout << "Enter rows/cols of the matrix : ";
    cin >> n;

    int a[n][n];
    
    int i=0;
    int k=1;

    while(k <= (n*n)){
        //left to right
        int j =i;
        while(j<n-1){
            a[i][j++] = k++; 
        }

        //top to bottom
        j = i+1;
        while(j<n-1){
            a[j++][n-i-1] = k++;
        }

        //right to left
        j = n-i-2;
        while(j>i){
            a[n-i-1][j--] = k++;
        }

        //bottom to top
        j = n-i-1;
        while (j>i){
            a[j--][i] = k++;
        }
        i++;
        

    }

    //Printing
    for(int k=0;k<n;k++){
        for(int l=0;l<n;l++){
            cout << a[k][l] << " ";
        }
        cout << endl;
    }
    return 0;
}