#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

#define int long long
#define pb push_back
#define endl '\n'
const int mod = 1e9+13;
const long long INF = 1e18;

void init(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}


string s;
vector<int> power;
vector<int> seg1,seg2;

void merge(int idx,int l,int r){
    if(l!=r){
        int mid = l + (r-l)/2;
        int leftLen = mid - l + 1;
        int rightLen = r - (mid+1) + 1;
        seg1[idx] = ((seg1[2*idx]*power[rightLen])%mod + seg1[2*idx+1])%mod;
        seg2[idx] = (seg2[2*idx] + (seg2[2*idx+1]*power[leftLen])%mod)%mod;
    }
}

void build(int idx,int l,int r){
    if(l==r){
        seg1[idx] = s[l] - 'a' + 1;
        seg2[idx] = s[l] - 'a' + 1;
        return;
    }
    int mid = l + (r-l)/2;
    build(2*idx,l,mid);
    build(2*idx+1,mid+1,r);
    merge(idx,l,r);
}   

void update(int idx,int l,int r,int pos,char ch){
    if(pos>r || pos<l) return;
    if(l == r){
        seg1[idx] = seg2[idx] = ch - 'a' + 1;
        return;
    }
    int mid = l + (r-l)/2;
    update(2*idx,l,mid,pos,ch);
    update(2*idx+1,mid+1,r,pos,ch);
    merge(idx,l,r);
}

pair<int,int> getSumPref(int idx,int l,int r,int lq,int rq){
    if(lq>r || rq<l) return {0,0};

    if(l>=lq && r<=rq) return {seg1[idx],r-l+1};

    int mid = l + (r-l)/2;

    pair<int,int> leftHash = getSumPref(2*idx,l,mid,lq,rq);
    pair<int,int> rightHash = getSumPref(2*idx+1,mid+1,r,lq,rq);

    int hash = ((leftHash.first*power[rightHash.second])%mod + rightHash.first)%mod;
    return {hash,leftHash.second + rightHash.second};
}

pair<int,int> getSumSuff(int idx,int l,int r,int lq,int rq){

    if(lq>r || rq<l) return {0,0};

    if(l>=lq && r<=rq) return {seg2[idx],r-l+1};

    int mid = l + (r-l)/2;

    pair<int,int> leftHash = getSumSuff(2*idx,l,mid,lq,rq);
    pair<int,int> rightHash = getSumSuff(2*idx+1,mid+1,r,lq,rq);

    int hash = (leftHash.first + (rightHash.first*power[leftHash.second])%mod)%mod;
    return {hash,leftHash.second + rightHash.second};
}

void solve(){
    int n,m;
    cin >> n >> m;

    cin >> s;

    seg1.assign(4*n,0);
    seg2.assign(4*n,0);

    int base = 37;
    power.assign(n,0);
    power[0] = 1;
    for(int i=1;i<n;i++){
        power[i] = (base*power[i-1])%mod;
    } 

    // for(int i=0;i<n;i++){
    //     pointHashForward[i] = ((s[i] - 'a' + 1)*power[n-1-i])%mod;
    // }

    // for(int i=n-1;i>=0;i--){
    //     pointHashBackward[i] = ((s[i] - 'a' + 1)*power[i])%mod;
    // }

    build(1,0,n-1);

    while(m--){

        int op;
        cin >> op;

        if(op == 1){

            int pos;
            cin >> pos;
            pos--;

            char ch;
            cin >> ch;

            // int newVal1 = ((ch-'a'+1)*power[n-1-pos])%mod;
            // int newVal2 = ((ch-'a'+1)*power[pos])%mod;

            update(1,0,n-1,pos,ch);
        }
        else{

            int lq,rq;
            cin >> lq >> rq;
            lq--,rq--;

            int getHash = getSumPref(1,0,n-1,lq,rq).first;
            int getRevHash = getSumSuff(1,0,n-1,lq,rq).first;

            if(getHash == getRevHash) cout << "YES";
            else cout << "NO";
            cout << endl;
        }
    }

}

int32_t main(){
    
    init();
    int _t = 1;
    //cin >> _t;
    while(_t--)
        solve();


    return 0;
}