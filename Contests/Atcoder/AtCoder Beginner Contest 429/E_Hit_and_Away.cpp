#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

#define int long long
#define pb push_back
#define endl '\n'
const int mod = 1e9+7;
const long long INF = 1e18;

void init(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n, m;
vector<vector<int>> graph;
vector<int> dist1, dist2, source1, source2;

// {distance, node, source_node}
using state = tuple<int, int, int>;

void solve(){

    cin >> n >> m;

    graph.assign(n + 1, vector<int>());

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    string s;
    cin >> s;

    vector<int> safe_nodes;
    vector<int> dangerous_nodes;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'S') {
            safe_nodes.push_back(i + 1);
        } else {
            dangerous_nodes.push_back(i + 1);
        }
    }

    dist1.assign(n + 1, INF);
    dist2.assign(n + 1, INF);
    source1.assign(n + 1, -1);
    source2.assign(n + 1, -1);

    queue<state> q;

    // Initialize the multi-source BFS from all safe nodes
    for (int safe_s : safe_nodes) {
        dist1[safe_s] = 0;
        source1[safe_s] = safe_s;
        q.push({0, safe_s, safe_s});
    }

    while (!q.empty()) {
        auto [d, u, src] = q.front();
        q.pop();

        // If this path's distance is worse than dist2[u], 
        // it can't possibly update dist1 or dist2.
        if (d > dist2[u]) {
            continue;
        }

        for (int &v : graph[u]) {
            int new_dist = d + 1;

            // If this path is from a source we already have a 
            // (better or equal) path from, skip it.
            if (src == source1[v] || src == source2[v]) {
                continue;
            }
            
            if (new_dist < dist1[v]) {
                // This new path is the new best.
                // The old 'best' becomes the 'second best'.
                dist2[v] = dist1[v];
                source2[v] = source1[v];
                
                dist1[v] = new_dist;
                source1[v] = src;
                
                q.push({new_dist, v, src});

            } else if (new_dist < dist2[v]) {
                // This new path is not the best, but it's
                // the new 'second best'.
                dist2[v] = new_dist;
                source2[v] = src;
                
                q.push({new_dist, v, src});
            }
        }
    }

    // Print answers for dangerous vertices in order
    for (int v : dangerous_nodes) {
        // The problem guarantees two safe nodes and a connected graph,
        // so dist2[v] should not be INF.
        cout << dist1[v] + dist2[v] << endl;
    }
}

int32_t main(){
    
    init();
    int _t = 1;
    // cin >> _t;
    while(_t--)
        solve();


    return 0;
}