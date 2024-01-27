#include<bits/stdc++.h>
using namespace std;

//s.c. -> O(1); T.C. -> O(N)
int main(){
    int arr[] = {4,2,7,8,9};
    int n = 5;

    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
            i++;
        }
    }
    //Check if modified array is sorted or not
    bool flag = true;
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            flag = false;
            break;
        }
    }
    if(flag == true) cout << "Almost Sorted";
    else cout<< "Not almost sorted";
}