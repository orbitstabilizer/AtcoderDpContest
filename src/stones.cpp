#include <bits/stdc++.h>
using namespace std;
int dp[100005] ;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a.begin(),a.end());
    for (int i= 0; i< a[0];i++){
        dp[i] = 1;
    }
    for (int i = a[0];i<= k;i++){
        for (int j = 0;j<n;j++){
            if (i-a[j]>=0){
                dp[i] = max(dp[i],dp[i-a[j]]);
            }else{
                break;
            }
        }
        dp[i] = !dp[i];
    }
    cout << ((dp[k])?"Second":"First") << endl;




    return 0;
}
