#include<iostream>
using namespace std;

int main(){
    int arr[] = {1,4,2,7,4};
    int n = sizeof(arr)/sizeof(int);

    int *ptr = arr;
    cout << ptr << endl;

    ptr[0] = 10; // *ptr = 10;
    ptr++;//ptr is pointing to the 2nd element
    *ptr=9;
    ptr--; //ptr is pointing to the 1st element

    /*for(int i=0;i<n;i++){
         cout << ptr[i] << " ";
    }*/

    for(int i=0;i<n;i++){
        cout << *ptr << " ";
        ptr++;
    }

    return 0;
}