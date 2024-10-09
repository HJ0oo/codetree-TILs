#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int N; // 1 ≤ N ≤ 10,000
    cin >> N ;

    vector<int> v;

    for (int i=0;i<N;i++){
        string command;
        cin >> command;
        int command_num;

        if (command == "push_back"){
            cin >> command_num;
            v.push_back(command_num);
        }
        else if (command == "pop_back"){
            v.pop_back();
        }
        else if (command == "size"){
            cout << v.size() << endl;
        }
        else{ //get k
            cin >> command_num;
            cout << v[command_num-1] << endl; // index 조심
        }

        // 근데 command_num 이 없는 경우를 나눠야하는데..
        // cin에 적용된 추출 연산은 공백을 추출할 값이 종료되는 것으로 인식합니다. 따라서 방금 작성한 코드는 항상 문장에서 첫 단어만 추출됩니다.
        // 공백이 포함된 한 줄의 입력된 모든 값을 받으려면 추출 연산자 대신 getline 함수를 사용해야 합니다.    
        
    }



    return 0;
}