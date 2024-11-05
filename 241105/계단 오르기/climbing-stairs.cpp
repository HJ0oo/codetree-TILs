#include <iostream>
using namespace std;
int dp[1001] = {};
int n;
int main() {
    cin >> n;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    for (int i = 4; i < n; i++){
        dp[i] = dp[i-2] + dp[i-3];
    }
    cout << dp[n] % 10007;
    return 0;
}