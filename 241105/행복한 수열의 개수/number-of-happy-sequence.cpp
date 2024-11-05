#include <iostream>
using namespace std;

int arr[101][101] = {0};
int n, m;
int ans = 0;
int main() {
    cin >> n >> m;

    for (int i = 0; i < n;i++){
        for (int j = 0; j < n;j++){
            cin >> arr[i][j];
        }
    }

    
    
    for (int i = 0; i < n;i++){
        int temp = -1;
        int happy = 1;
        for (int j = 0; j < n;j++){
            if (arr[i][j] != temp){
                happy = 1;
            }
            else {
                happy += 1;
            }
            temp = arr[i][j];
        }
        if (happy == m) {
            ans += 1;
        }
    }

    for (int j = 0; j < n;j++){
        int temp = -1;
        int happy = 1;
        for (int i = 0; i < n;i++){
            if (arr[i][j] != temp){
                happy = 1;
            }
            else {
                happy += 1;
            }
            temp = arr[i][j];
        }
        if (happy >= m) {
            ans += 1;
        }
    }



    cout << ans;

    return 0;
}