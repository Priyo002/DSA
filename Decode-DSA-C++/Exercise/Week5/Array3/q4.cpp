#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cout << "Enter the size : ";
    cin >> n;
    vector<int> arr(n);

    cout << "Enter your elements : ";
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    int j=0;

   for(int i=0;i<n;i++){
    if(arr[i]!=0){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        j++;
    }
   }

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
      
    return 0;
}
