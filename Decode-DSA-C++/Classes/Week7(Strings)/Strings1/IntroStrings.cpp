#include<iostream>
using namespace std;

int main(){
    
    char str[] = {'a','b','c','d','\0','f'};// '\0' -> NULL character
    //char str[] = "abcde";
    for(int i=0;str[i]!='\0';i++){
        cout << str[i];
    }

}