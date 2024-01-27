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
    
    int max = INT_MIN;
    for(int i=0;i<arr.size();i++){
        if(arr[i]>max) max = arr[i];
    }

    cout << "Largest is : " << max << endl;

    int max2 = INT_MIN;
    for(int i=0;i<arr.size();i++){
        if(arr[i]>max2 && arr[i]
        != max) max2 = arr[i];
    }

    cout << "Second Largest is : " << max2 << endl;

    int max3 = INT_MIN;
    for(int i=0;i<arr.size();i++){
        if(arr[i]>max3 && arr[i]
        != max && arr[i] != max2) max3 = arr[i];
    }

    cout << "Third Largest is : " << max3;

    return 0;
}