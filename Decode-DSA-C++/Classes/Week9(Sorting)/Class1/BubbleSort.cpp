#include<bits/stdc++.h>
#include<vector>
using namespace std;

int main(){

    int arr[6] = {5,-4,0,3,2,1};
    int n = sizeof(arr)/sizeof(int);

    // //Bubble Sort; 
    //T.C. -> O(n2), S.C. -> O(1)
    // for(int i=0;i<n-1;i++){//n+1 passes
    //     //traverse
    //     for(int j=0;j<n-1-i;j++){
    //         if(arr[j]>arr[j+1]){
    //             swap(arr[j],arr[j+1]);
    //         }
    //     }   
    // }

    //Bubble Sort Optimised 
    for(int i=0;i<n-1;i++){//n+1 passes
        //traverse
        bool flag = true;
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                flag = false;
            }
        }
        if(flag==true) break;//swap did not happen   
    }

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}