#include<bits/stdc++.h>
using namespace std;


int main(){
    int arr[] = {4,2,7,9,8};
    int n = sizeof(arr)/sizeof(int);
    int brr[n];
    for(int i=0;i<n;i++){
        brr[i]=arr[i];
    }
    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        if(i==0){
            if(brr[i]==arr[i] || brr[i]==arr[i+1])
            continue;
            else {
                cout << false;
                return 0;
            }
        }
        else if(i==n-1){
            if(brr[i]==arr[i] || brr[i]==arr[i-1])
            continue;
            else{
                cout << false;
                return 0;
            }
        }
        else{
            if(brr[i]==arr[i] || brr[i]==arr[i-1] || brr[i]==arr[i+1]){
                continue;
            }
            else{
                cout << false;
                return 0;
            }
        }
    }
    cout << true;
    
    //for(int i=0;i<n;i++) cout<< arr[i] << " ";
}