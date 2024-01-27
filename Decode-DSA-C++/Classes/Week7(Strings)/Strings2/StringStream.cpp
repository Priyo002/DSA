#include<bits/stdc++.h>
#include<sstream>
using namespace std;

int main(){
    string str = "Priyo is a bad boy";
    stringstream ss(str);
    string temp;

    while(ss>>temp){
        cout << temp << endl;
    }

}