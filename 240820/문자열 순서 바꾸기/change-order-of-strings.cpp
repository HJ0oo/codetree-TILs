#include <iostream>
using namespace std;
#include <string>

int main() {
    
    string c1, c2 ;
    cin >> c1 >> c2 ;
    
    string temp = c1 ;
    c1 = c2 ;
    c2 = temp ;

    cout << c1 << "\n"<< c2 ;

    return 0;
}