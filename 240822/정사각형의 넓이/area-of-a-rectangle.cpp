#include <iostream>
using namespace std;

int main() {
    int n ;
    cin >> n;
    if (n < 5) {
        cout << "tiny";
    }
        
    else {
        cout << n * n;
    }
        
    return 0;
}