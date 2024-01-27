#include<bits/stdc++.h>
using namespace std;

int main(){


    int m;
    cout << "Enter rows of 1st Matrix : ";
    cin >> m;
    int n;
    cout << "Enter cols of 1st Matrix : ";
    cin >> n;
    
    int p;
    cout << "Enter rows of 2nd Matrix : ";
    cin >> p;
    int q;
    cout << "Enter cols of 2nd Matrix : ";
    cin >> q;

    if(n==p){
        int a[m][n];
        int b[p][q];
        cout << "Enter elements of 1st Matrix : ";
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin >> a[i][j];
            }
        }
        cout << "Enter elements of 2nd Matrix : ";
        for(int i=0;i<p;i++){
            for(int j=0;j<q;j++){
                cin >> b[i][j];
            }
        }

        //Resultant Matrix
        int res[m][q];
        for(int i=0;i<m;i++){
            for(int j=0;j<q;j++){
                //Multiply
                res[i][j] = 0;
                for(int k=0;k<p;k++){
                    res[i][j] += a[i][k] * b[k][j];
                }
            }
        }

        cout << endl;
        for(int i=0;i<m;i++){
            for(int j=0;j<q;j++){
                cout << res[i][j] << " ";
            }
            cout << endl;
        }

    }
    else cout << "The matrices cannot be multiplied";



    return 0;
}