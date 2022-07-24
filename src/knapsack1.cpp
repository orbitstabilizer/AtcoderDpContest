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
    for (int i = 0; i < N; i++) {
        cin >> item[i][0] >> item[i][1];
    }
    vector<ll> dp(W+1,INT_MIN);
    dp[0] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = W; j >= item[i][0]; j--) {
            dp[j] = max(dp[j], dp[j - item[i][0]] + item[i][1]);
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
    return 0;
}

