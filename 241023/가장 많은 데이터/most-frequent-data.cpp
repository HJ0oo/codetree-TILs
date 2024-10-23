#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    unordered_map <string, int> my_map;
    string arr[1000001];
    int max_num = 1;

    for (int i=0;i<n;i++){
        cin >> arr[i];
        my_map[arr[i]] += 1; 
        /*
        C++에서 std::map이나 std::unordered_map과 같은 연관 컨테이너들이
        기본적으로 default-initialization을 지원하기 때문에
            // 처음 나온 문자열이라면 1을 직접 적어줘야 합니다.
            if(freq.find(words[i]) == freq.end())
                freq[words[i]] = 1;
            // 이미 나와있던 문자열이라면 1을 더해줍니다.
            else
                freq[words[i]]++;
        이런 식으로 안해도 돌아감.

        자료형에 따라 자동 초기화되는 기본값:
            정수형(int): 0
            실수형(float, double): 0.0
            bool: false
            포인터형: nullptr
        */
        max_num = max(max_num,my_map[arr[i]]);
    }

    cout << max_num ;
    

    return 0;
}