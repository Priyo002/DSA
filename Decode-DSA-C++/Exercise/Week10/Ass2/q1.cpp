#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[]={7,8,5,4,3,2,1};
    int n = sizeof(arr)/sizeof(int);
    int x = 3;
    int lo = 0;
    int hi = n - 1;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(arr[mid]==x){
            cout << mid;
            break;
        }
        else if(arr[mid]<x) hi = mid - 1;
        else lo = mid + 1;
    }
    //cout << -1;
    return 0;
}