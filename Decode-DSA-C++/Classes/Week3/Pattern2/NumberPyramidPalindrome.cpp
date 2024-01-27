#include<iostream>
using namespace std;

int main(){

    int n;
    cout << "Enter your number : ";
    cin >>n;

    for(int i=1;i<=n;i++){
        for(int s=1;s<=n-i;s++){
            cout << " ";
        }
        int k=1;
        for(int j=1;j<=i;j++){
        cout << k;
        k++;
        }
        for(int l=i-1;l>=1;l--){
            cout << l;
        }
        cout << endl;

    }

    return 0;
}
