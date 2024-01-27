#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int arr[] = {0,1,2,3,4,5,7,8,9};
    int n = sizeof(arr)/sizeof(int);

    /*
    //T.C. -> O(n)
    for(int i=0;i<n;i++){
        if(i!=arr[i]){
            cout << i;
            break;
        }
    }
    */

    //T.C. -> O(logn)
    int lo = 0;
    int hi = n-1;
    int ans = -1;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(arr[mid]==mid){
            lo = mid + 1;
        }
        else{//arr[mid]!=mid
            ans = mid;
            hi = mid - 1;
        }
    }
    cout << ans;

    return 0;
}