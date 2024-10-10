#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;
    unordered_set<int> my_set;
    // my_set = {}; - 이거 없어도 됨!!
    for (int i=0;i<N;i++){
        string command;
        int command_num;
        cin >> command >> command_num;
        
        if (command == "find"){
            // my_set.find(command_num); 
            // unordered_set<int>::iterator 타입을 출력하려고 시도했지만,
            // 해당 타입은 직접 출력할 수 없어서 발생한 오류
            // 없으면 my_set.end() 출력
            if (my_set.find(command_num) == my_set.end()){
                cout << "false"<< endl;
            }
            else {
                cout << "true"<< endl;
            }

        }
        else if (command == "add"){
            my_set.insert(command_num);
        }
        else { // remove
            my_set.erase(command_num);
        }
        
    }
    


    return 0;
}