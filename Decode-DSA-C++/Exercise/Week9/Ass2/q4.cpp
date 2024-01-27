#include<bits/stdc++.h>
using namespace std;


int main(){
    int arr[] = {5,4,3,2,1};
    int n = sizeof(arr)/sizeof(int);
    sort(arr,arr+n);
    int sum1 = 0;
    int x = 1;
    for(int i=n-1;i>=0;i--){
        sum1 = arr[i]*x + sum1;
        x *= 10;
    }
    for(int i=n-1;i>=1;i--){
        if(arr[i]!=arr[i-1]){
            swap(arr[i],arr[i-1]);
            break;
        }
    }
    int sum2 = 0;
    x = 1;
    for(int i=n-1;i>=0;i--){
        sum2 = arr[i]*x + sum2;
        x *= 10;
    }
    cout << sum1 + sum2;
}