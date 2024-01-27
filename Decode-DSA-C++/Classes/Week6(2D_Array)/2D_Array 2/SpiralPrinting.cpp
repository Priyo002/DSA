#include<bits/stdc++.h>
using namespace std;

int main(){


    int m;
    cout << "Enter rows of the Matrix : ";
    cin >> m;
    int n;
    cout << "Enter cols of the Matrix : ";
    cin >> n;

    int a[m][n];
    cout << "Enter elements of the Matrix : ";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
        }
    }

    int minr = 0;
    int maxr = m-1;
    int minc = 0;
    int maxc = n-1;
    
    while(minr<=maxr && minc<=maxc){
    //Right
    for(int r= minc;r<=maxc;r++){
        cout << a[minr][r] << " ";
    }
    minr++;
    if(minr > maxr || minc > maxc) break;
    //Down
    for(int d = minr;d<=maxr;d++){
        cout << a[d][maxc] << " ";
    }
    maxc--;
    if(minr > maxr || minc > maxc) break;
    //left
    for(int l = maxc; l>=minc;l--){
        cout << a[maxr][l] << " ";
    }
    maxr--;
    if(minr > maxr || minc > maxc) break;
    //Up
    for(int u = maxr; u>=minr;u--){
        cout << a[u][minc] << " ";
    }
    minc++;
}
    return 0;
}