#include<bits/stdc++.h>
using namespace std;

int main(){

    int arr[4][2];
    // rows -> 3 (0-2)
    // columns -> 3 (0-2)

    cout << "Enter your roll and marks : " << endl;
     for(int i=0;i<=3;i++){
        for(int j=0;j<=1;j++){
            cin >> arr[i][j];
        }
    }

    cout << endl;
    for(int i=0;i<=3;i++){
        for(int j=0;j<=1;j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    
    
}