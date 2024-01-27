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

    bool flag = false;
    for(int i=0;i<n;i++){
        int j;
        for(j=0;j<n;j++){
            if(i!=j && arr[i]== arr[j]){
                //Repeating elements
                break;
            }
        }
        if(j==n){ 
        cout << arr[i] << endl; 
        flag = true;
        break;

        }
    }

    if(flag) cout << "Non repeating element is present ";
    else cout << "No non-repeating element is present";

      
    return 0;
}