#include<bits/stdc++.h>
using namespace std;

int main(){

    int arr[5] = {5,4,3,2,1};
    int n = sizeof(arr)/sizeof(int);
    
    int k;
    //Selection Sort
    for(int i=0;i<n-1;i++){
        int mini = INT_MAX;
        k = -1;
        for(int j=i;j<n;j++){
            if(arr[j]<mini){ 
                mini = arr[j];
                k = j;
            }
        }
        swap(arr[i],arr[k]);
    }

    //for-each loop
    for(int ele : arr){
        cout << ele << " ";
    }
}