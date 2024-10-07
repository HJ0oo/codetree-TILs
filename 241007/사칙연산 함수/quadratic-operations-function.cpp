#include <iostream>
using namespace std;

void cal(int num1,char thing,int num2) {
    int ans;
    if (thing == '+'){
        ans = num1 + num2;
        cout << num1 << " " << thing << " " << num2 << " " << "=" << " " << ans;
    }
    else if (thing == '-'){
        ans = num1 - num2;
        cout << num1 << " " << thing << " " << num2 << " " << "=" << " " << ans;
    }
    else if (thing == '/'){
        ans = num1 / num2;
        cout << num1 << " " << thing << " " << num2 << " " << "=" << " " << ans;

    }
    else if (thing == '*'){
        ans = num1 * num2;
        cout << num1 << " " << thing << " " << num2 << " " << "=" << " " << ans;
    }
    else {
        cout << "False";
        // 여기 꼭 반환값이 있어야?
    }


}





int main() {
    int a, b;
    char o;
    cin >> a >> o >> b ;
    cal(a,o,b);
    return 0;
}