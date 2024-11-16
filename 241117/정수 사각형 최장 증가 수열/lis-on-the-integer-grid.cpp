#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>

#define MAX_N 500
#define DIR_NUM 4

using namespace std;

// 변수 선언
int n;
int grid[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];

vector<tuple<int, int, int> > cells;
int ans;

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

int main() {
    // 입력
    cin >> n;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> grid[i][j];

    // 각 칸에 적혀있는 정수값 기준으로
    // 오름차순이 되도록 칸의 위치들을 정렬합니다.
    // 편하게 정렬하기 위해
    // (칸에 적혀있는 값, 행 위치, 열 위치) 순으로 넣어줍니다.
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cells.push_back(make_tuple(grid[i][j], i, j));
    
    // 오름차순으로 정렬을 진행합니다.
    sort(cells.begin(), cells.end());

    // 처음 DP 값들은 전부 1로 초기화해줍니다. (해당 칸에서 시작하는 경우)
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            dp[i][j] = 1;

    // 정수값이 작은 칸부터 순서대로 보며
    // 4방향에 대해 dp 값을 갱신해줍니다.
    for(int i = 0; i < (int) cells.size(); i++) {
        int x, y;
        tie(ignore, x, y) = cells[i];

        int dx[DIR_NUM] = {-1, 1,  0, 0};
        int dy[DIR_NUM] = { 0, 0, -1, 1};

        // 인접한 4개의 칸에 대해 갱신을 진행합니다.
        for(int j = 0; j < DIR_NUM; j++) {
            int nx = x + dx[j], ny = y + dy[j];
            if(InRange(nx, ny) && grid[nx][ny] > grid[x][y])
                dp[nx][ny] = max(dp[nx][ny], dp[x][y] + 1);
        }
    }

    // 전체 수들 중 최댓값을 찾습니다.
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            ans = max(ans, dp[i][j]);

    cout << ans;
    return 0;
}