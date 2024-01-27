#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int arr[] = {1,2,4,5,9,15,18,21,24};
    int n = sizeof(arr)/sizeof(int);
    int x = 19;
    
    /*
        T.C. -> O(n)
        for(int i=0;i<n;i++){
            if(arr[i]>x){
                cout << arr[i-1];
                break;
            }
        }
    */

    //Using Binary Search : T.C. -> O(logn)
    int lo = 0;
    int hi = n-1;
    bool flag = false;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(arr[mid]==x) {
            cout << arr[mid-1];
            flag = true;
            break;
        }
        else if(arr[mid]<x) lo = mid+1;
        else if(arr[mid]>x) hi = mid - 1;
    }
    if(flag==false){//if element is not in the array
        cout << arr[hi];
    }

    return 0;
}