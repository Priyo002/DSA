#include<iostream>
#include<vector>
using namespace std;

int main(){
    
    vector<int> v;
    
    v.push_back(6);
    v.push_back(1);
    v.push_back(9);
    v.push_back(10);
    v.push_back(11);

    for(int i=0;i<v.size();i++){
        cout << v[i] << " ";
    }

    cout << endl;
    cout << "Capacity = " << v.capacity() << endl;
    cout << "size = " << v.size() << endl;
    v.pop_back();
    cout << "Capacity = " << v.capacity() << endl;
    cout << "size = " << v.size() << endl;

    for(int i=0;i<v.size();i++){
        cout << v[i] << " ";
    }

    return 0;
}