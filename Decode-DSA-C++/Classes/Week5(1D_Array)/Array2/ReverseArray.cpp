#include<iostream>
#include<vector>
using namespace std;

void display(vector<int> &a){
    for(int i=0;i<a.size();i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

int main(){

    int n;
    cout << "Enter array size : ";
    cin >> n;

    vector<int> v(n);
   
    cout << "Enter the elements of the array : ";
    for(int i=0;i<v.size();i++){
        cin >> v[i];
    }

    display(v);

    vector<int> v2(n);

    for(int i=0;i<n;i++){
        // i + j = size - 1;
        int j= n - 1 - i;
        v2[i] = v[j];
        
    }
    
    display(v2);

    return 0;
}