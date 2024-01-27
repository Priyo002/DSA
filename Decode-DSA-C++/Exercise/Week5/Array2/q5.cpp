#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cout << "Enter the size : ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the elements : ";

    for(int i=0;i<arr.size();i++){
        cin >> arr[i];
    }
    cout << endl;
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    
    for(int i=0;i<n;i++){
        if(i % 2 == 0) arr[i] +=10;
        else arr[i] *= 2;
    }

    cout << endl;
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    
    return 0;
}