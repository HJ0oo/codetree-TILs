#include <iostream>
using namespace std;
int n;
long long arr[20] = {0};

int main() {
    cin >> n;
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 1 * 1 + 1 * 1;
    for (int i = 3; i < n+1; i++) {
        for (int j = i-1; j >= 0; i--) {
            arr[i] += arr[j] * arr[i-1-j];
        }
    }
    cout << arr[n];
    return 0;
}