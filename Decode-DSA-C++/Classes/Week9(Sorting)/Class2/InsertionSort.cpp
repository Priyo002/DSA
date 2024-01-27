#include<bits/stdc++.h>
using namespace std;

int main(){

    int arr[5] = {5,4,3,2,1};
    int n = sizeof(arr)/sizeof(int);
    
    int k;
    //Insertion Sort
    for(int i=1;i<n;i++){
        int j = i;
        while(j>=1 && arr[j]<arr[j-1]){
            swap(arr[j],arr[j-1]);
            j--;
        }
    }

    //for-each loop
    for(int ele : arr){
        cout << ele << " ";
    }
}