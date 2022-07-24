#include <bits/stdc++.h>
using namespace std;
double dp[3000][3000];
double f(int n, int k, vector<double>& p) {
    if (p.size()-k < n) {
        dp[n][k] = 0;
        return 0;
    }
    if (n == 0) {
        dp[n][k] = 1;
        return 1;
    }
    if (dp[n][k] >-0.5){
        return dp[n][k];
    }
    return dp[n][k] = (1-p[k])*f(n , k+1, p) + p[k] * f(n - 1, k + 1, p);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;  cin >> n;
    vector<double> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = -1;
        }
    }
    cout << fixed << setprecision(10) << f( (n / 2)+1, 0, p) << endl;
    return 0;
}
