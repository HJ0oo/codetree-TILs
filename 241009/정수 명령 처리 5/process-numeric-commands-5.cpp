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
        int command_num;
        cin >> command >> command_num;
        // 근데 command_num 이 없는 경우를 나눠야하는데..?

        if (command == "push_back"){
            v.push_back(command_num);
            cout << "#1#" << command_num << endl;
        }
        else if (command == "pop_back"){
            cout << "#2#" << command_num << endl;
            v.pop_back();
        }
        else if (command == "size"){
            cout << "#3#" << v.size() << endl;
        }
        else{
            //get k
            cout << "#4#" << v[command_num] << endl;
        }
        
        
        
        
    }



    return 0;
}