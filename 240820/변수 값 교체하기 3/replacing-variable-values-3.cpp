#include <iostream>
using namespace std;

int main() {
    
    int a = 3;
    int b = 5;
    int temp ;


    temp = a ;
    a = b ;
    b = temp ;

    cout << a << "\n" << b ;



    return 0;
}