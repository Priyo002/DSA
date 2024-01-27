#include<iostream>
using namespace std;

int main(){

    int n;
    cout << "Enter the size ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements ";

    for(int i=0;i<=n-1;i++) 
        cin >> arr[i];

    int max = arr[0];
    for(int i=0;i<=n-1;i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }

    int max2 = arr[0];
    for(int i=0;i<=n-1;i++){
        if((arr[i]>max2) && (arr[i]!= max)){
            max2 = arr[i];
        }
    }
    cout << max2;

    return 0;
}