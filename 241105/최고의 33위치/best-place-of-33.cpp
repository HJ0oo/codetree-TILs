#include <iostream>
#include <algorithm>
using namespace std;

/*
// 방법 1. 슬라이딩 윈도우 방식
int arr[21][21] = {0};

// 3x3 부분 배열의 합을 계산하는 함수
int calculateSum(int x, int y) {
    int sum = 0;
    for (int i = x; i < x + 3; i++) {
        for (int j = y; j < y + 3; j++) {
            sum += arr[i][j];
        }
    }
    return sum;
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    int maxSum = -1;
    
    // 슬라이딩 윈도우로 3x3 부분 배열의 합 중 최대값 찾기
    for (int i = 0; i <= N - 3; i++) {
        int currentSum = calculateSum(i, 0); // 초기 3x3 부분 배열의 합
        maxSum = max(maxSum, currentSum);

        for (int j = 1; j <= N - 3; j++) {
            // 다음 열로 이동하면서 차이만큼 갱신
            for (int k = 0; k < 3; k++) {
                currentSum -= arr[i + k][j - 1];
                currentSum += arr[i + k][j + 2];
            }
            maxSum = max(maxSum, currentSum);
        }
    }

    cout << maxSum;
    return 0;
}
*/

// 방법 2. 누적합 방식
const int MAX = 21; // 배열의 최대 크기 설정
int arr[MAX][MAX];
int sum[MAX][MAX]; // 누적 합 배열

// 2차원 누적합 이용 부분배열 합 헷갈릴 때 여기 그림 참고하기 : https://code-angie.tistory.com/22
// 2D 누적 합 배열 생성
void calculatePrefixSum(int N) {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            sum[i][j] = arr[i - 1][j - 1]
                        + sum[i - 1][j]
                        + sum[i][j - 1]
                        - sum[i - 1][j - 1];
        }
    }
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    calculatePrefixSum(N); // 누적 합 배열 계산

    int maxSum = -1;

    // 각 3x3 부분 배열의 합 계산 및 최대 값 갱신
    for (int i = 1; i <= N - 2; i++) {
        for (int j = 1; j <= N - 2; j++) {
            int currentSum = sum[i + 2][j + 2] 
                             - sum[i + 2][j - 1] 
                             - sum[i - 1][j + 2] 
                             + sum[i - 1][j - 1];
            maxSum = max(maxSum, currentSum);
        }
    }

    cout << maxSum;

    return 0;
}