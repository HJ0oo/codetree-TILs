#include <iostream>
using namespace std;

int main() {
    // int로 받아서 음수를 -로 사용함ㅎㅎ
    int a,b,c;
    cin >> a >> b >> c ;
    // cout << a <<"\n"; // 10
    // cout << b <<"\n"; // -1234
    // cout << c <<"\n"; // -5678
    cout << 0 << a << c << b ;

    return 0;
}

// 사실 이렇게 하라고 준 것.
// int main() {
//     int a, b, c;
//     cin >> a;
//     cin.get();
//     cin >> b;
//     cin.get();
//     cin >> c;

//     // 출력
//     cout << "010-" << c << "-" << b;
//     return 0;
// }


// # cin
// 문자, 문자열 모두 입력 받을 수 있습니다.
// 공백이나 개행 입력 시 공백 이전까지의 값만 결과로 받아들입니다.

// # cin.get()
// 문자 하나만 입력이 가능하며 공백과 개행도 입력으로 포함합니다

// # getline()
// 문자열을 입력 받습니다.
// 공백이나 개행도 입력으로 포함합니다.