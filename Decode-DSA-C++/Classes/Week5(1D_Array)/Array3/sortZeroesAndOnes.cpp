#include<bits/stdc++.h>
using namespace std;

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort1(vector<int> &v){
    int n = v.size();
    int no0 = 0;
    int no1 = 0;
    for(int i=0;i<n;i++){
        if(v[i]==0) no0++;
        else no1++;
    }

    for(int i=0;i<n;i++){
        if(i<no0) v[i] = 0;
        else v[i] = 1;
    }
}

void sort2(vector<int> &v){
    int n = v.size();
    int i = 0;
    int j = n-1;

    while(i<j){
        if(v[j]==1) j--;
        if(v[i]==0) i++;
        if(i>j) break;
        if(v[i]==1 && v[j]==0){
            swap(v[i],v[j]);
            i++;
            j--;
        }
    }
}
int main(){
    
    vector<int> v;

    v.push_back(1);
    v.push_back(1);
    v.push_back(0);
    v.push_back(1);
    v.push_back(0);
    v.push_back(1);
    v.push_back(1);
    v.push_back(0);

    for(int i=0;i<v.size();i++){
        cout << v[i] << " ";
    }
    cout << endl;

    //sort1(v);
    sort2(v);

    for(int i=0;i<v.size();i++){
        cout << v[i] << " ";
    }

}