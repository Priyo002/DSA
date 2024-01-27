#include<bits/stdc++.h>
using namespace std;

int main(){

    int arr[3][3] = {1,2,3,4,5,6,7,8,9};
    // rows -> 3 (0-2)
    // columns -> 3 (0-2)

    int n = sizeof(arr)/sizeof(int);
    cout << "Size " << n << endl;

     for(int i=0;i<=2;i++){
        for(int j=0;j<=2;j++){
            cin >> arr[i][j];
        }
    }

    cout << endl;
    for(int i=0;i<=2;i++){
        for(int j=0;j<=2;j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    
    
}