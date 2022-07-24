#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int h,w;
    cin >> h >> w;
    vector<vector<int>> a(h,vector<int>(w));
    char tmp;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> tmp;
            a[i][j] = tmp == '#' ? 0 : 1;
        }
    }
    vector<vector<int>> dp(h,vector<int>(w,0));
    for (int i = 0;i< h ;i++){
        if (a[i][0] == 0) {
            break;
        }
        dp[i][0] = 1;
    }
    for (int i = 0;i< w ;i++){
        if (a[0][i] == 0) {
            break;
        }
        dp[0][i] = 1;
    }

    for (int i = 1; i < h; i++) {
        for (int j = 1; j < w; j++) {
            if (a[i][j] ) {
                dp[i][j] = (dp[i - 1][j] + dp[i ][j-1]) %mod;
            }
        }
    }
    cout << dp[h-1][w-1] << endl;





    return 0;
}
