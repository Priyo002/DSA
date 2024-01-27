#include<bits/stdc++.h>
using namespace std;

void reverse(vector<int> &v){
    int i = 0;
    int j= v.size()-1;
    while(i<j){
        int temp = v[i];
        v[i] = v[j];
        v[j] = temp;
        i++;
        j--;
    }
}



int main(){

    int n;
    cout << "Enter the size : ";
    cin >> n;

    vector<int> arr(n);
    vector<int> vrr(n);

    cout << "Enter the elements : ";

    for(int i=0;i<arr.size();i++){
        cin >> arr[i];
        vrr[i] = arr[i];
    }
    for(int i=0;i<arr.size();i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    reverse(arr);

    // for(int i=0;i<arr.size();i++){
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    // for(int i=0;i<arr.size();i++){
    //     cout << vrr[i] << " ";
    // }
    // cout << endl;

    bool flag = false;
    for(int i=0;i<n;i++){
        if(arr[i]!=vrr[i]){
            flag = true;
            break;
        }
    }
    if(flag == false) cout << "Palindrome";
    else cout << "Not Palindrome";
    
    return 0;
}