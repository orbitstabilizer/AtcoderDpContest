#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,K;
    cin >> n>> K;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;
    for (int i = 0 ;i< n-1; i++) {
        for (int k = 1;k<= K;k++){
            dp[i+k] = min(dp[i+k], dp[i] + abs(a[i+k] - a[i]));
        }
    }
    cout << dp[n-1] << endl;
    return 0;
}
