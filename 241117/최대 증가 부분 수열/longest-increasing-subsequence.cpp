#include <iostream>
#include <numeric> 
using namespace std;

int n;
int arr[1001] = {0};
int dp[10001] = {0};
int max_thing = -1;

int main() {
    cin >> n;
    for (int i=1;i<n+1;i++){
        cin >> arr[i];
        max_thing = max(max_thing, arr[i]);
    }

    for (int i=1; i<n+1; i++){
        dp[arr[i]] = reduce(dp,dp + arr[i], 0, max<int>) + 1;
        // cout <<  dp[arr[i]]  << " , i는 " << arr[i] << endl;
    }

    cout << reduce(dp,dp + max_thing+1, 0, max<int>);
    return 0;
}