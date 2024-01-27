#include<iostream>
#include<vector>
using namespace std;

int main(){
    
    vector<int> v;// You need not mention the size

    //Inserting from the back
    v.push_back(6);
    v.push_back(9);
    v.push_back(1);

    //Updating 
    v[0]= 10;

    cout << v.capacity() << endl;
    cout << v.size() << endl;

    for(int i=0;i<3;i++){
        cout << v[i] << " ";
    }



    return 0;
}