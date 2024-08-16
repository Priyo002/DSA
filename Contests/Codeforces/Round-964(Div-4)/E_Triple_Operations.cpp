#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void init(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

vector<int> arr;
bool flag = false;

int f(int n){
    int cnt = 0;
    while(n>0){
        cnt++;
        n /= 3;
    }
    return cnt;
}

#define N 200100

void preCompute(){
    if(flag) return;
    flag = true;

    arr.clear();
    arr.resize(N+1,0);

    for(int i=1;i<=N;i++){
       arr[i] = f(i);
    }

    for(int i=1;i<=N;i++) arr[i] += arr[i-1];
}

void solve(){
    int l,r;
    cin >> l >> r;

    int ans = arr[r];
    ans -= arr[l];
    ans += 2*(arr[l] - arr[l-1]);

    cout << ans << endl;
}

int32_t main(){
    
    init();

    preCompute();

    int _t = 1;
    cin >> _t;
    while(_t--)
        solve();

}