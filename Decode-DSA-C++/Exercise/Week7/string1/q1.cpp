#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cout << "Enter the size : ";
    cin >> n;
    char str[n];
    for(int i=0;i<n;i++){
        cin >> str[i];
    }
    int i=0;
    while(str[i]!='\0'){
        if(i%2 != 0) str[i] = '#';
        i++;
    }
    cout << endl;
    for(int i=0;i<n;i++) cout << str[i];
    return 0;
}