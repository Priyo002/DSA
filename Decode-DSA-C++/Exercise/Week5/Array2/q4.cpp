#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cout << "Enter the size : ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the elements : ";

    for(int i=0;i<arr.size();i++){
        cin >> arr[i];
    }
    
    int sum = 0, sum1 = 0;;
    for(int i=0;i<n;i++){
        if(i % 2 == 0) sum +=arr[i];
        else sum1 += arr[i];
    }

    cout << "Difference is " << sum - sum1;
    
    return 0;
}