/* #include <iostream>
#include <algorithm>

#define MAX_NUM 200

using namespace std;

int n, m;
int grid[MAX_NUM][MAX_NUM];

// 가능한 모든 모양을 전부 적어줍니다.
int shapes[6][3][3] = {
    {{1, 1, 0},
    {1, 0, 0},
    {0, 0, 0}},

    {{1, 1, 0},
    {0, 1, 0},
    {0, 0, 0}},

    {{1, 0, 0},
    {1, 1, 0},
    {0, 0, 0}},

    {{0, 1, 0},
    {1, 1, 0},
    {0, 0, 0}},

    {{1, 1, 1},
    {0, 0, 0},
    {0, 0, 0}},

    {{1, 0, 0},
    {1, 0, 0},
    {1, 0, 0}},
};

// 주어진 위치에 대하여 가능한 모든 모양을 탐색하며 최대 합을 반환합니다.
int GetMaxSum(int x, int y) {
    int max_sum = 0;
    
    for(int i = 0; i < 6; i++) {
        bool is_possible = true;
        int sum = 0;
        for(int dx = 0; dx < 3; dx++)
            for(int dy = 0; dy < 3; dy++) {
                if(shapes[i][dx][dy] == 0) continue;
                if(x + dx >= n || y + dy >= m) is_possible = false;
                else sum += grid[x + dx][y + dy];
            }

        if(is_possible)
            max_sum = max(max_sum, sum);
    }
    
    return max_sum;
}

int main() {
	
	cin >> n >> m;
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> grid[i][j];
	
	int ans = 0;
	
    // 격자의 각 위치에 대하여 탐색하여줍니다.
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			ans = max(ans, GetMaxSum(i, j));
	
	cout << ans;
	
	return 0;
}
*/
#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int arr[201][201] = {0};
int max_ans = -1; // 자연수만 들어있으므로 -1로 설정

int cal_case_1(int s_i, int s_j) {
    // ㄱ자 모양의 최댓값 = 2*2에서 최소를 빼기
    if ( (s_i + 1 < n ) && ( s_j + 1 < m )) {
        return arr[s_i][s_j] + arr[s_i+1][s_j] + arr[s_i][s_j+1]+ arr[s_i+1][s_j+1] - min({arr[s_i][s_j], arr[s_i+1][s_j], arr[s_i][s_j+1], arr[s_i+1][s_j+1]});
    }
    return 0;
}


int cal_case_2(int s_i, int s_j) {
    // ㅣ자 모양의 최댓값
    if (s_i + 2 < n ) {
        return arr[s_i][s_j] + arr[s_i+1][s_j] + arr[s_i+2][s_j];
    }
    return 0;
}

int cal_case_3(int s_i, int s_j) {
    // ㅡ자 모양의 최댓값
    if (s_j + 2 < m ) {
        return arr[s_i][s_j] + arr[s_i][s_j+1] + arr[s_i][s_j+2];
    }
    return 0;
}



int main() {
    cin >> n >> m ;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> arr[i][j] ;
        }
    }


    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            max_ans = max(cal_case_1(i,j), max_ans);
            max_ans = max(cal_case_2(i,j), max_ans);
            max_ans = max(cal_case_3(i,j), max_ans);

        }
    }

    cout << max_ans;



    return 0;
}