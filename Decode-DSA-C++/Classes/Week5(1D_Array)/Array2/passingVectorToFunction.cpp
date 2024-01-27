#include<iostream>
#include<vector>
using namespace std;

//Pass by value (New vector is created)

/*void change(vector<int> a){
    a[0] = 10;
    for(int i=0;i<a.size();i++){
        cout << a[i] << " ";
    }

    cout << endl;
}*/


//Pass by reference
void change(vector<int> &a){
    a[0] = 10;
}

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

    change(v);

    for(int i=0;i<v.size();i++){
        cout << v[i] << " ";
    }


    return 0;
}