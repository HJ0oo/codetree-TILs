#include <iostream>
using namespace std;
#include <unordered_map>
#include <string>

int main() {
    
    int n;
    cin >> n ;
    unordered_map<int,int> my_map;
    for (int i=0;i<n;i++){
        string command;
        cin >> command ;
        if (command == "add"){
            int k,v;
            cin >> k >> v ;
            /*
            std::unordered_map::insert() 함수가 중복된 키에 대해 삽입을 허용하지 않기 때문입니다.
            my_map.insert({k, v});를 사용하면 키 k가 이미 존재하는 경우 새로운 값 v가 삽입되지 않고 무시됩니다.
            std::unordered_map::insert()는 중복된 키를 처리하지 않고, 이미 존재하는 키에 대해 아무 작업도 하지 않습니다.
            반면, **my_map[k] = v;**는 k가 이미 존재하는 경우 값을 덮어쓰기(overwrite) 합니다.
            따라서 **값을 수정하려면 my_map[k] = v;**을 사용하는 것이 적절합니다.
            */

            // my_map.insert({k,v}); // 이렇게 하면 오류
            my_map[k] = v ;
        }
        else if (command == "remove"){ // 잘못된 입력 주어지지 않으니까 그냥 제거하면 됨.
            int k;
            cin >> k ;
            my_map.erase(k);
        }
        else if (command == "find"){
            int k;
            cin >> k ;
            if (my_map.find(k) != my_map.end()) {
                cout << my_map[k] << endl;
            }
            else {
                cout << "None" << endl;
            }

        }
        else { // 디버깅용
            cout << "error" << endl;
        }
    }


    return 0;
}