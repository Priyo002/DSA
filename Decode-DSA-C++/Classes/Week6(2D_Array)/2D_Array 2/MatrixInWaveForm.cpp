#include<bits/stdc++.h>
using namespace std;

int main(){


    int m;
    cout << "Enter rows of the Matrix : ";
    cin >> m;
    int n;
    cout << "Enter cols of the Matrix : ";
    cin >> n;

    int a[m][n];
    cout << "Enter elements of the Matrix : ";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
        }
    }

    cout << endl;
    //Wave Print
    for(int i=0;i<m;i++){
        if(i%2==0){
            for(int j=0;j<n;j++){
                cout << a[i][j] << " ";
            }
        }
        else{
            for(int j=n-1;j>=0;j--){
                cout << a[i][j] << " ";
            }
        }
    }



    return 0;
}