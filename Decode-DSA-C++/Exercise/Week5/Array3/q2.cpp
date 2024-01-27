#include<bits/stdc++.h>
using namespace std;

int go(vector<int> &a,int val, int &size){
    int carry = 0;

    for(int i =0; i<size;i++){
        int prod = a[i] * val + carry;

        a[i] = prod%10;
        carry = prod/10;
    }
    while(carry){
        a[size] = carry%10;
        carry = carry/10;
        size++;
    }

    return size;
}

int main(){

    int n;
    cout << "Enter your factorial number ";
    cin >> n;
    vector<int>arr(500, 0);

    int size = 1;
    arr[0] = 1;
    for(int i=2;i<=n;i++){
        go(arr,i,size);
    }

    for(int i= size-1;i>=0;i--){
        cout << arr[i];
    }

    return 0;
}