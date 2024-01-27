#include<iostream>
using namespace std;

int main(){

    int n;
    cout << "Enter your number : ";
    cin >> n;


    for(int i=1;i<=n+1;i++){
        
        char k = 'A';

        if(i%2!=0){
        for(int j=1;j<=i;j++){
        cout << j;
        }
        }
        else{
        for(int j=1;j<=i;j++){
        cout << k;
        k++;
        }
        }
        cout << endl;
    }

    return 0;
}