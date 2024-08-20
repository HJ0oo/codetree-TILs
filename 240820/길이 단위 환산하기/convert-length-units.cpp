#include <iostream>
using namespace std;

int main() {
    cout << fixed;
    cout.precision(1);
    
    double ft = 30.48 ;
    double input ;
    cin >> input ;
    
    cout << input * ft ;

    return 0;
}