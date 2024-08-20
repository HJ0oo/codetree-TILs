#include <iostream>
using namespace std;

int main() {
    
    cout << fixed;

    cout.precision(1);


    double ft = 30.48;
    double mi = 160934;



    cout << 9.2 << "ft = " << 9.2 * ft << "cm\n" ;
    cout << 1.3 << "mi = " << 1.3 * mi << "cm";


    return 0;
}