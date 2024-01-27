#include<bits/stdc++.h>
using namespace std;

void display(vector<int> &a){
    for(int i=0;i<a.size();i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

void reversePart(int i,int j, vector<int> &v){
    while(i<=j){
        int temp = v[i];
        v[i] = v[j];
        v[j] = temp;
        i++;
        j--;
    }
}

void reverse(vector<int> &v){
    
    int i = 0;
    int j = v.size() - 1;

    while(i<=j){
        int temp = v[i];
        v[i] = v[j];
        v[j] = temp;
        i++;
        j--;
    }
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

    int k;
    cout << "Steps of Rotation : ";
    cin >> k;

    if(k>n) k = k%n;

    reversePart(0,n-k-1,v);
    reversePart(n-k,n-1,v);
    reverse(v);

    //reverse(v.begin(),v.end()); inbuilt function for vector
    
    display(v);

    return 0;
}