#include <iostream>
using namespace std;
#include <unordered_set>


int main() {
    // 헷갈리지 말고 선언 + 입력 세트로 하기!
    int N;
    cin >> N;
    //
    unordered_set<int> set1;
    for (int i=0;i<N;i++){ // 아악 int 빼먹지좀마라!
        int new_input;
        cin >> new_input;
        set1.insert(new_input);
    }

    int M;
    cin >> M;
    for (int i=0;i<M;i++){
        int new_input2;
        cin >> new_input2;
        if (set1.find(new_input2) == set1.end()){
            cout << "0" << endl;
        }
        else{
            cout << "1" << endl;
        }
    }


    return 0;
}