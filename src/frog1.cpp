#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;
    for (int i = 0 ;i< n-1; i++) {
        dp[i+1] = min(dp[i+1], dp[i] + abs(a[i+1] - a[i]));
        dp[i+2] = min(dp[i+2], dp[i] + abs(a[i+2] - a[i]));
    }
    cout << dp[n-1] << endl;

    return 0;
}
