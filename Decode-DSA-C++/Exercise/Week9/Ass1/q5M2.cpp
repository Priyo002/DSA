#include<bits/stdc++.h>
using namespace std;

//Unique elements
//S.C. -> O(1); T.C. -> O(N2)


int main(){
    int arr[] = {4,2,7,9,8};
    int n = sizeof(arr)/sizeof(int);

    bool flag = true;
    for(int i=0;i<n;i++){
        int cnt = 0;
        for(int j=0;j<n;j++){
            if(i==j) continue;
            if(arr[j]>arr[i]) cnt++;
        }
        int aidx = n - cnt - 1;
        int diff = abs(aidx-i);
        if(diff>1){
            flag = false;
            break;
        }

    }
    cout << flag;

    
}