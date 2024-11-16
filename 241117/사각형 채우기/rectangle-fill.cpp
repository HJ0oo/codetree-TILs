#include <iostream>
using namespace std;
int arr[1001] = {0};
int n;

int main() {
    /*
    f(1) = 1
    f(2) = 2
    f(n) = f(n-1) + f(n-2)
    */
    cin >> n;
    arr[1] = 1;
    arr[2] = 2;
    for (int i=3; i<n+1; i++) {
        arr[i] = arr[i-1] + arr[i-2];
        arr[i] %= 10007;
    }
    cout << arr[n];
    return 0;
}