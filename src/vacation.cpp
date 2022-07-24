#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    vector<int> dp[3] = {vector<int>(n+1,0),vector<int>(n+1,0),vector<int>(n+1,0)};
    int abc[3] = {0,0,0};
    for(int i=0;i<n;i++){
        cin >> abc[0] >> abc[1] >> abc[2];
        for (int j = 0; j < 3; ++j) {
            dp[j][i + 1] += max(dp[(j + 1) % 3][i] + abc[(j + 1) % 3], dp[(j + 2) % 3][i] + abc[(j + 2) % 3]);
        }

    }

    cout << max(dp[0][n], max(dp[1][n], dp[2][n])) << endl;

    return 0;
}

