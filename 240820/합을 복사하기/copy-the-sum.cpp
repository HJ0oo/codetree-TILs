#include <iostream>
using namespace std;

int main() {
    
    int a = 1 , b = 2, c = 3 ;
    int temp = a + b + c ;
    a = b = c = temp;
    cout << a << " " << b << " " << c ;  

    return 0;
}