#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,count=0,x;
    cout << "Enter the size : ";
    cin >> n;

    vector<int> arr(n);

    for(int i=0;i<arr.size();i++){
        cin >> arr[i];
    }
    
    cout << "Enter x : ";
    cin >> x;

    for(int i=0;i<arr.size();i++){
        if(arr[i]>x) count ++;
    }

    cout << "Answer is : " << count;

    return 0;
}