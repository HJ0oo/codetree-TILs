#include <iostream>
using namespace std;
// long long dp[1001] = {};
int dp[1001] = {};
int n;
int main() {
    cin >> n;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    for (int i = 4; i <= n; i++){
        dp[i] = dp[i-2] + dp[i-3];
        // cout << i <<" "<< dp[i] << endl;
        dp[i] %= 10007;
    }
    cout << dp[n];
    return 0;
}