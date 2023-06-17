#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<int> x(n);
    vector<ll> y(n);
    bool isp = false;
    for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
    vector<vector<ll>> dp(n,vector<ll> (2));
    dp[0][0] = y[0];
    dp[0][1] = 0;
    if(x[0] == 1) isp = true;
    for(int i = 1; i < n; i++) {
        if(x[i] == 0) {
            ll back_dp = max(dp[i-1][0],dp[i-1][1]);
            if(isp) {
                dp[i][0] = back_dp + y[i];
                dp[i][1] = back_dp + y[i];
            }
            else {
                
                dp[i][0] = back_dp + y[i];
                dp[i][1] = back_dp;
            }
            isp = false;
            
        }
        else {
            if(!isp) {
                ll back_dp = max(dp[i-1][0],dp[i-1][1]);
                dp[i][0] = back_dp + y[i];
                dp[i][1] = back_dp;
                isp = false;
            }
            else continue;
        }
    }
    
    ll ans = max(dp[n-1][0],dp[n-1][1]);
    cout << ans << endl;
}
