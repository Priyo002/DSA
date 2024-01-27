#include<iostream>
#include<vector>
using namespace std;

int main(){
    
    int x;
    cout << "Enter target : ";
    cin >> x;

    int n;
    cout << "Enter array size : ";
    cin >> n;

    vector<int> v(n);
   
    cout << "Enter the elements of the array : ";
    for(int i=0;i<v.size();i++){
        cin >> v[i];
    }

    for(int i=0;i<v.size()-1;i++){
        for(int j=i+1;j<v.size();j++){
            if(v[i]+v[j]==x){
                cout << i << "," << j;
                cout << endl;
            }
        }
    }
    
    return 0;
}