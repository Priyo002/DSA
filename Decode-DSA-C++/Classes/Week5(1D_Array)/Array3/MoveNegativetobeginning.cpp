#include<bits/stdc++.h>
using namespace std;

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort2(vector<int> &v){
    int n = v.size();
    int i = 0;
    int j = n-1;

    while(i<j){
        if(v[j]>0) j--;
        if(v[i]<0) i++;
        if(i>j) break;
        if(v[i]>0 && v[j]<0){
            swap(v[i],v[j]);
            i++;
            j--;
        }
    }
}
int main(){
    
    int n;
    cout << "Enter size : ";
    cin >> n;
    vector<int> v(n);

    cout << "Enter elements : ";
    for(int i=0;i<n;i++) cin >> v[i];

    for(int i=0;i<v.size();i++){
        cout << v[i] << " ";
    }
    cout << endl;
    
    sort2(v);

    for(int i=0;i<v.size();i++){
        cout << v[i] << " ";
    }

}