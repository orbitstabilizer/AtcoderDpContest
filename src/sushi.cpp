#include <bits/stdc++.h>
using namespace std;
typedef array<int,3> tri;
double dp[301][301][301];
int n;
double f(tri root){
    if(root[1]==0 && root[2] == 0 && root[0] == 1) {
        return dp[root[0]][root[1]][root[2]] = n;
    }
    if(dp[root[0]][root[1]][root[2]] >-0.5) {
        return dp[root[0]][root[1]][root[2]];
    }


    double sm = root[0] + root[1] + root[2];
    double ans = n/sm;
    for(int i=0;i<3;i++){
        if (root[i] > 0){
            auto tmp = root;
            tmp[i]--;
            if (i > 0) {
                tmp[i - 1]++;
            }
            ans+=(f(tmp)) * root[i]/sm;
        }
    }
    return dp[root[0]][root[1]][root[2]] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    tri root;
    fill(root.begin(), root.end(), 0);
    int tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        root[tmp-1]++;
    }
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            for (int k = 0; k <= n; k++)
                dp[i][j][k] = -1;

    cout << fixed << setprecision(10) << f(root) << endl;

    return 0;
}
