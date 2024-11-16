#include <iostream>
using namespace std;
long long arr[1001] = {0};
long long sum[1001] = {0};
int n;

int main() {
    /*
    f(1) = 1
    f(2) = 2
    f(n) = f(n-1) + f(n-2)
    */
    cin >> n;
    arr[1] = 2;
    arr[2] = 7;
    arr[3] = 22;

    sum[1] = 2;
    sum[2] = 9;
    sum[3] = 31;    

    for (int i=4; i<n+1; i++) {
        arr[i] = arr[i-1] * 2 + arr[i-2] * 3 + sum[i-3] * 2 + 2;
        sum[i] = sum[i-1] + arr[i];
    }
    cout << arr[n] % 1000000007;
    return 0;
}