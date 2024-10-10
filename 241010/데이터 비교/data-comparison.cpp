#include <iostream>

using namespace std;
// 원소의 "종류"가 정확히 동일한지 - set 굳
#include <unordered_set> // 세미콜론 붙이지 마라


int main() {
    int n ;
    cin >> n ;
    // 두 번째 줄에는 수열 1의 원소들이 공백을 두고 주어집니다.
    // n개의 숫자가 공백을 기준으로 들어옴 - set 안에 넣으면 됨!
    unordered_set<int> my_set_1;
    for (int i=0;i<n;i++){ ///////// int 빼먹지마!!!!!!!!!!
        int new_input_num;
        cin >> new_input_num;
        my_set_1.insert(new_input_num);
    }


    int m ;
    cin >> m ;
    unordered_set<int> my_set_2;
    for (int i=0;i<m;i++){
        int new_input_num;
        cin >> new_input_num;
        // my_set_2.insert(new_input_num);
        if (my_set_1.find(new_input_num) == my_set_1.end()){
            cout << "0 "; 
        }
        else {
            cout << "1 "; 
        }
    }





    return 0;
}