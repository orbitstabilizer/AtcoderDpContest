#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    vector<int> adj[n+1];
    int x,y;
    for (int _ = 0; _< m ; _++) {
        cin >> x >> y;
        adj[x].push_back(y);
    }
    // topological sort adj
    vector<int> topo;
    vector<int> indeg(n+1,0);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            indeg[adj[i][j]]++;
        }
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo.push_back(u);
        for (int i = 0; i < adj[u].size(); i++) {
            indeg[adj[u][i]]--;
            if (indeg[adj[u][i]] == 0) {
                q.push(adj[u][i]);
            }
        }
    }


    vector<int> dp(n+1,0);
    for (int i = 0; i < topo.size(); i++) {
        int u = topo[i];
        for (int j = 0; j < adj[u].size(); j++) {
            dp[adj[u][j]] = max(dp[adj[u][j]], dp[u] + 1);
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;


    return 0;
}
