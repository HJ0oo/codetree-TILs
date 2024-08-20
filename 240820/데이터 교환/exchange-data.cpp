#include <iostream>
using namespace std;

int main() {
    
    int a = 5 , b = 6 , c = 7 ;
    int temp1 , temp2, temp3 ;

    temp1 = a ; 
    temp2 = b ;
    temp3 = c ;

    b = temp1 ;
    c = temp2 ;
    a = temp3 ;

    cout << a << "\n" << b << "\n" << c ;




    return 0;
}