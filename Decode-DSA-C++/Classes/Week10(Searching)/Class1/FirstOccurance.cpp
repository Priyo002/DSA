#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int arr[] = {1,2,2,3,3,3,3,4,4,5,5,6};
    int n = sizeof(arr)/sizeof(int);
    int x = 1;

    //Using Binary Search : T.C. -> O(logn)
    int lo = 0;
    int hi = n-1;
    bool flag = false;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(arr[mid]==x){
            if(mid==0){
                flag = true;
                cout << mid;
                break;
            }
            if(arr[mid-1]!=x){
                flag = true;
                cout << mid;
                break;
            }
            else{
                hi = mid - 1;
            }
        }
        else if(arr[mid]<x){
            lo = mid + 1;
        }
        else{
            hi = mid - 1;
        }
    }
    if(flag==false)
    cout << -1;

    return 0;
}