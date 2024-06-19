#include <bits/stdc++.h>
#define lli long long int
#define li long int
#define ld long double
using namespace std;
const lli mod = 1e9 + 7;

const int n = 7;
bool visited[n][n];
int reserved[49];
string path;

void f(int r, int c, int &ans, int &steps){

    //BaseCase
    if (r == n - 1 && c == 0){
        ans += (steps == n * n - 1);
        return;
    }
    
    //Prunning (Optimization)
    bool f1 = ((c==0 || (visited[r][c+1] && visited[r][c-1])) && (r-1>=0 && r+1<n && !visited[r-1][c] && !visited[r+1][c]));
    bool f2 = ((r==0 || (visited[r+1][c] && visited[r-1][c])) && (c+1<n && c-1>=0 && !visited[r][c+1] && !visited[r][c-1]));
    bool f3 = ((c==n-1 || (visited[r][c+1] && visited[r][c-1])) && (r+1<n && r-1>=0 && !visited[r+1][c] && !visited[r-1][c]));
    bool f4 = ((r==n-1 || (visited[r+1][c] && visited[r-1][c])) && (c-1>=0 && c+1<n && !visited[r][c+1] && !visited[r][c-1]));

    if(f1 || f2 || f3 || f4) return;


    //Check & Move
    visited[r][c] = true;

    if (path[steps]!='?'){
        char ch = path[steps];
        if(ch=='U'){
            if(r-1>=0 && !visited[r-1][c]){
                steps++;
                f(r-1,c,ans,steps);
                steps--;
            }
        }
        else if(ch=='R'){
            if(c+1<n && !visited[r][c+1]){
                steps++;
                f(r,c+1,ans,steps);
                steps--;
            }
        }
        else if(ch=='D'){
            if(r+1<n && !visited[r+1][c]){
                steps++;
                f(r+1,c,ans,steps);
                steps--;
            }
        }
        else{
            if(c-1>=0 && !visited[r][c-1]){
                steps++;
                f(r,c-1,ans,steps);
                steps--;
            }
        }
    }
    else{
        if(r-1>=0 && !visited[r-1][c]){
            steps++;
            f(r-1,c,ans,steps);
            steps--;
        }
        if(c+1<n && !visited[r][c+1]){
            steps++;
            f(r,c+1,ans,steps);
            steps--;
        }
        if(r+1<n && !visited[r+1][c]){
            steps++;
            f(r+1,c,ans,steps);
            steps--;
        }
        if(c-1>=0 && !visited[r][c-1]){
            steps++;
            f(r,c-1,ans,steps);
            steps--;
        }
    }

    visited[r][c] = false;
    

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> path;
    
    int ans = 0, steps = 0;
    f(0, 0, ans, steps);

    cout << ans;
    
    return 0;
}
