#include <iostream>
#include <unordered_map>

using namespace std;

int main() {

    int n,m;
    cin >> n >> m ;


    unordered_map<int,int> my_map;
    for (int i=0;i<n;i++){
        int input_num ;
        cin >> input_num;
        
        if (my_map.find(input_num) == my_map.end()) {
            my_map[input_num] = 1;
        }
        else {
            my_map[input_num] += 1; // 이렇게 가능?
        }
        

    }

    for (int i=0;i<m;i++){
        // 바로 출력
        int input_num ;
        cin >> input_num;
        if (my_map.find(input_num) == my_map.end()) {
            cout << 0 << " " ;
        }
        else {
            cout << my_map[input_num] << " " ;
        }
        
    }
    
    return 0;
}