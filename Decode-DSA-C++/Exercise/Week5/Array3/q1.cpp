#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cout << "Enter the size : ";
    cin >> n;
    int arr[n];

    cout << "Enter your elements : ";
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    int x;
    cout << "Enter your x : ";
    cin >> x;

    int count = 0;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(arr[i]+arr[j]+arr[k] == x){
                    count++;
                    cout << "Triplets are " << arr[i] << " " << arr[j] << " "<< arr[k];
                    cout << endl;
                }
            }
        }
    }

    cout << "No. of triplets are " << count;   
    return 0;
}