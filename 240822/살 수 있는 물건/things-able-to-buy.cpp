#include <iostream>
using namespace std;
# include <string>

int main() {
    int n ;
    cin >> n ;


    string result ;
    if (n >= 3000){
        cout << "book";
    }
    else if (n >= 1000){
        cout << "mask";
    }
    else {
        cout << "no";
    }


    return 0;
}