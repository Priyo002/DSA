#include<bits/stdc++.h>
using namespace std;

int main(){

    int arr[] = {0,0,0,1,1,1,1,1};
    int n = sizeof(arr)/sizeof(int);
    int x = 1;
    int i = 0;
    int j = n -1;
    int f=0,l=0;
    //last occurance
    while(i<=j){
        int mid = (i+j)/2;
        if(arr[mid]==x){
            if(mid==n-1){
                l = mid;
                break;
            }
            if(x!=arr[mid+1]){
                l = mid;
                break;
            }
            else if(x==arr[mid+1]){
                i = mid + 1;
            }
        }
        else if(arr[mid]<x) i = mid + 1;
        else j = mid - 1;
    }
    //first occurance
    i=0;
    j=n-1;
    while(i<=j){
        int mid = (i+j)/2;
        if(arr[mid]==x){
            if(mid==0){
                f = mid;
                break;
            }
            if(x!=arr[mid-1]){
                f = mid;
                break;
            }
            else if(x==arr[mid-1]){
                j = mid - 1;
            }
        }
        else if(arr[mid]<x) i = mid + 1;
        else j = mid - 1;
    }
    if(l-f+1 !=0) cout << l-f+1;
    else
    cout << -1;

    return 0;
}