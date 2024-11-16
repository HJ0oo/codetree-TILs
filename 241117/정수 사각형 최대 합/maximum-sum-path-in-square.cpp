#include <iostream>
#include <algorithm>
using namespace std;

int arr[101][101] = {0};
int ans[101][101] = {0};
int n;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    // (0,0) > (n-1,n-1) 오른쪽 혹은 밑으로만 이동
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (i == 0) {
                ans[i][j] = arr[i][j] + ans[i][j-1];
            }
            if (j == 0) {
                ans[i][j] = arr[i][j] + ans[i-1][j];
            }
            if (( i != 0) && (j != 0)){
                ans[i][j] = max(ans[i][j-1],ans[i-1][j]) + arr[i][j];
            }            
            // cout << i << " " << j << " " << ans[i][j] << endl;
        }
    }
    cout << ans[n-1][n-1];
    return 0;
}