#include <iostream>
using namespace std;
#include <unordered_set>

int main() {
    int n ;
    cin >> n ; // 선언만 하지 말고 꼭 입력 받기
    unordered_set<int> my_set;
    for (int i=0;i<n;i++){
        int new_input;
        cin >> new_input; // 선언만 하지 말고 꼭 입력 받기
        my_set.insert(new_input);
    }

    cout << my_set.size();
    
    // // error 2
    // cout << my_set.end();
    // // my_set.end()는 출력할 수 없는 반복자(iterator) 타입이라 발생한 에러입니다.

    
    return 0;
}