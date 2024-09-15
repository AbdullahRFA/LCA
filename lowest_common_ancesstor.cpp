#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<int> g[N];
int par[N];

void dfs(int n, int p) {
    par[n] = p;
    for (int x : g[n]) {
        if (x == p) continue;
        dfs(x, n);
    }
}

vector<int> path_of_node(int x) {
    vector<int> res;
    while (x != -1) {
        res.push_back(x);
        x = par[x];
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    int n;
   // cout << "Enter the number of nodes: ";
    cin >> n;
    
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    dfs(1, -1);
    
    //cout << "Enter the number of queries: ";
    int Q;
    cin >> Q;
    
    while (Q--) {
        int p, q;
        //cout << "Enter query nodes: ";
        cin >> p >> q; 
        
        vector<int> path_of_p = path_of_node(p);
        vector<int> path_of_q = path_of_node(q);
        
        int ln_of_lca = min(path_of_p.size(), path_of_q.size());
        int lca = -1;
        
        for (int i = 0; i < ln_of_lca; i++) {
            if (path_of_p[i] == path_of_q[i]) {
                lca = path_of_p[i];
            } else {
                break;
            }
        }
        
        cout << "Lowest Common Ancestor: " << lca << endl;
    }

    return 0;
}
