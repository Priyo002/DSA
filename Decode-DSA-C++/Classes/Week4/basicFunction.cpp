#include<iostream>
using namespace std;

void starTriangle(int a,int b,int c){

    for(int i=1;i<=a;i++){
        for(int j=1;j<=i;j++) cout << "*";
        cout << endl;
    }
    for(int i=1;i<=b;i++){
        for(int j=1;j<=i;j++) cout << "*";
        cout << endl;
    }
    for(int i=1;i<=c;i++){
        for(int j=1;j<=i;j++) cout << "*";
        cout << endl;
    }
}

int main(){

    int a,b,c;
    cout << "Enter your numbers : ";
    cin >> a >> b >> c;

    starTriangle(a,b,c);

    return 0;
     
}