/*
n×n 크기의 격자 정보가 주어졌을 때,
(1, 1)에서 시작하여 오른쪽 혹은 밑으로만 이동하여 (n, n)으로 간다고 했을 때
거쳐간 위치에 적혀있는 수들 중 |최댓값-최솟값|을 최소로 만드는 프로그램
*/

#include <iostream>
#include <algorithm>
#include <climits>

#define MAX_N 100
#define MAX_R 100

using namespace std;

// 변수 선언
int n;
int num[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];

int ans = INT_MAX;

void Initialize() {
    // 전부 INT_MAX로 초기화합니다.
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            dp[i][j] = INT_MAX;

    // 시작점의 경우 dp[0][0] = num[0][0]으로 초기값을 설정해줍니다
    dp[0][0] = num[0][0];

    // 최좌측 열의 초기값을 설정해줍니다.
    for(int i = 1; i < n; i++)
        dp[i][0] = max(dp[i - 1][0], num[i][0]);

    // 최상단 행의 초기값을 설정해줍니다.
    for(int j = 1; j < n; j++)
        dp[0][j] = max(dp[0][j - 1], num[0][j]);
}

int Solve(int lower_bound) {
    // lower_bound 미만의 값은 사용할 수 없도록
    // num값을 변경해줍니다.
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(num[i][j] < lower_bound)
                num[i][j] = INT_MAX;
    
    // DP 초기값 설정
    Initialize();

    // 탐색하는 위치의 위에 값과 좌측 값 중에 작은 값과
    // 해당 위치의 숫자 중에 최댓값을 구해줍니다.
    for(int i = 1; i < n; i++)
        for(int j = 1; j < n; j++)
            dp[i][j] = max(min(dp[i - 1][j], dp[i][j - 1]), num[i][j]);
        
    return dp[n - 1][n - 1];
}

int main() {
    // 입력
    cin >> n;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> num[i][j];

    // 최솟값을 lower_bound라고 가정했을 때
    // lower_bound 이상의 수들만 사용하여 
    // 이동한다는 조건하에서
    // 최댓값을 최소로 만드는 DP 문제를 풀어줍니다.
    for(int lower_bound = 1; lower_bound <= MAX_R; lower_bound++) {
        int upper_bound = Solve(lower_bound);
        
        // 다 진행했음에도 여전히 INT_MAX라면 
        // 그러한 이동이 불가능하다는 뜻이므로
        // 패스합니다.
        if(upper_bound == INT_MAX)
            continue;
        
        // 답을 갱신합니다.
        ans = min(ans, upper_bound - lower_bound);
    }

    cout << ans;
    return 0;
}