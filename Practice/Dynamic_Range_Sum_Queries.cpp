#include<bits/stdc++.h>
using namespace std;
#define int long long
//#define mp make_pair
const int MOD=1000000007;
vector<int> arr(200010,0),t(800000,0);
void build(int index,int l,int r){
    if(l==r){
        t[index]=arr[l];
        return;
    }
    int mid=(l+r)/2;
    build(2*index,l,mid);
    build(2*index+1,mid+1,r);
    t[index]=t[2*index]+t[2*index+1];
}
void update(int index,int l,int r,int pos,int x){
    if(pos<l || pos>r)return;
    if(l==r){
        t[index]=x;
        // arr[index]=x;
        return;
    }
    int mid=(l+r)/2;
    update(2*index,l,mid,pos,x);
    update(2*index+1,mid+1,r,pos,x);
    t[index] = t[2*index] + t[2*index+1];
}
int query(int index,int l,int r,int lq,int rq){
    if(l > rq || lq > r) return 0;
    if(lq<=l && rq>=r ){
        return t[index];
    }
    int mid=(l+r)/2;
    return query(2*index,l,mid,lq,rq)+query(2*index+1,mid+1,r,lq,rq);
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    build(1,0,n-1);
    while(q--){
        int k;
        cin>>k;
        if(k==1){// update
            int ind,val;
            cin>>ind>>val;
            ind--;
            update(1,0,n-1,ind,val);
        }
        else{
            int l,r;
            cin>>l>>r;
            l--;r--;
            cout<<query(1,0,n-1,l,r)<<endl;;
        }
    }
}