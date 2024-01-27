#include<bits/stdc++.h>
#include<vector>
using namespace std;

//while maintaining relative order

int main(){

    int arr[] = {5,0,1,2,0,0,4,0,3};
    int n = sizeof(arr)/sizeof(int);
    
    for(int i=0;i<n-1;i++){
        //traverse
        for(int j=0;j<n-1-i;j++){
            if(arr[j]==0){
                swap(arr[j],arr[j+1]);
            }
        }   
    }

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}