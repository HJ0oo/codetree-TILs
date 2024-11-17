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
    }

    cout << reduce(dp,dp + max_thing+1, 0, max<int>);
    return 0;
}

/*
#include <iostream>
#include <climits>
#include <algorithm>

#define MAX_NUM 1000

using namespace std;

// dp[i] :
// 마지막으로 고른 원소의 위치가 i인
// 부분 수열 중 최장 부분 수열의 길이
int dp[MAX_NUM + 1];
int n;
int a[MAX_NUM + 1];

void Initialize() {
    // 최대를 구하는 문제이므로, 
    // 초기에는 전부 INT_MIN을 넣어줍니다.
    for(int i = 0; i <= n; i++)
        dp[i] = INT_MIN;
    
    // 0번째 index와 비교했을 때 항상 갱신될 수
    // 있는 값을 넣어줍니다.
    dp[0] = 0;
    a[0] = 0;
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    Initialize();

    for(int i = 1; i <= n; i++){
        // i번째 보다 앞에 있는 원소들 중 
        // a[i]보다는 값이 작은 곳을 골라 바로 그 뒤에 
        // 새로운 원소인 a[i]를 추가했을 때의 
        // 부분 수열 중 최대 부분 수열의 길이를 계산합니다.
        for(int j = 0; j < i; j++)
            if(a[j] < a[i])
                dp[i] = max(dp[i], dp[j] + 1);
    }

    // 마지막 원소의 위치가 i일 때의 부분 수열들 중
    // 가장 길이가 긴 부분 수열을 고릅니다.
    int answer = 0;
    for(int i = 0; i <= n ; i++)
        answer = max(answer, dp[i]);

    cout << answer;
}
*/