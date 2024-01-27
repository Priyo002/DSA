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
    int vowel = 0, count = 0;

    while(str[i]!='\0'){
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') vowel++;
        if(str[i] >=65 && str[i] <=90 || str[i] >= 97 && str[i] <=122) count++;
        i++;
    } 
    cout << "Consonants = " << abs(count - vowel) <<endl;
    //for(int i=0;i<n;i++) cout << str[i];
    return 0;
}