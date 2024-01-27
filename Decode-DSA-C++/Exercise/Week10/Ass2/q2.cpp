#include<bits/stdc++.h>
using namespace std;

int main(){

    int arr[] = {1,2,3,4,4,4,5,5,6,7};
    int n = sizeof(arr)/sizeof(int);
    int x = 5;
    int i = 0;
    int j = n -1;

    while(i<=j){
        int mid = (i+j)/2;
        if(arr[mid]==x){
            if(x!=arr[mid+1]){
                cout << mid;
                return 0;
            }
            else if(x==arr[mid+1]){
                i = mid + 1;
            }
        }
        else if(arr[mid]<x) i = mid + 1;
        else j = mid - 1;
    }
    cout << -1;

    return 0;
}