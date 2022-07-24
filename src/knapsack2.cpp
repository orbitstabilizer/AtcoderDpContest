#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef array<int,2> vec2;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int W,N;
    cin >> N >> W;
    vector<vec2> item(N);
    ll sm_val = 0;
    for (int i = 0; i < N; i++) {
        cin >> item[i][0] >> item[i][1];
        sm_val += item[i][1];
    }
    vector<ll> dp(sm_val+1,1e18+5);
    dp[0] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = sm_val ; j >= item[i][1]; j--) {
            dp[j] = min(dp[j], dp[j - item[i][1]] + item[i][0]);
        }
    }
    int ans = 0;
    for (int i = 0; i <= sm_val; i++) {
        if (dp[i] <= W) {
            ans = max(ans, i);
        }
    }
    cout << ans << endl;

    return 0;
}

